#include "Trader_IO.hpp"
#include <sstream>
#include <ctime>
#include <iostream>
#include <cctype> // For isalpha and isdigit
#include <conio.h> // For _getch
#include <limits> // Include for numeric_limits
#include <iostream>
#include "TRADINGPLATFORM_DEF.hpp" // for generateUUID();
#include "Trader_DB.hpp"



/*------------------------------------------------------------------------------------------------------------------------*/
/*-----------------------------------------------Input Pre-check functions------------------------------------------------*/
string removeRedundantSpaces(const string& str)
{
    string result;
    bool prevSpace = false; // Flag to keep track of previous space

    for (char c : str) {
        if (isspace(c)) {
            if (!prevSpace) {
                result.push_back(c);
                prevSpace = true;
            }
        }
        else {
            result.push_back(c);
            prevSpace = false;
        }
    }

    return result;
}


bool isValidEmailFormat(const string& email)
{
    // Check if the email has '@' and '.'
    size_t atPos = email.find('@');
    size_t dotPos = email.rfind('.');

    if (atPos == string::npos || dotPos == string::npos || dotPos < atPos) {
        return false;
    }

    // Check if there is at least one character before '@' and after '.' in the email
    if (atPos == 0 || dotPos == email.length() - 1) {
        return false;
    }

    return true;
}

bool isValidPassword(const string& password)
{
    // Check for minimum length
    if (password.length() < 8) {
        return false;
    }

    // Check for at least one capital letter and one special character
    bool hasCapitalLetter = false;
    bool hasSpecialChar = false;

    for (char c : password) {
        if (isupper(c)) {
            hasCapitalLetter = true;
        }
        else if (!isalnum(c)) {
            hasSpecialChar = true;
        }
    }

    return hasCapitalLetter && hasSpecialChar;
}

bool isValidPhoneNumber(const string& phoneNumber) {
    // Check if the phone number contains only digits and is not empty
    for (char c : phoneNumber) {
        if (!isdigit(c) && c != '+' && c != '0') {
            return false;
        }
    }

    // Check if the phone number starts with '+' or '00'
    if (phoneNumber.size() >= 2 && (phoneNumber[0] == '+' || (phoneNumber[0] == '0' && phoneNumber[1] == '0'))) {
        // Additional checks for phone number format or length can be added here

        return true;
    }

    return false;
}

bool isLeapYear(int year) {
    return ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0));
}

bool isValidDate(const std::string& dateStr) {
    std::istringstream dateStream(dateStr);
    int year, month, day;

    char delimiter; // To store the hyphens

    dateStream >> year >> delimiter >> month >> delimiter >> day;

    if (!dateStream || delimiter != '-' || year < 0 || month < 1 || month > 12 || day < 1) {
        return false;
    }

    int daysInMonth[] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

    if (isLeapYear(year)) {
        daysInMonth[2] = 29; // February has 29 days in a leap year
    }

    if (day > daysInMonth[month]) {
        return false;
    }

    return true;
}

bool isValidDateFormat(const string& dateStr)
{
    istringstream iss(dateStr);
    int year, month, day;
    char separator;

    if (iss >> year >> separator >> month >> separator >> day) {
        // Check if all characters were read successfully and separator is correct
        return (iss.eof() && separator == '-');
    }

    return false;
}

bool isOver18YearsOld(const string& dateStr)
{

    tm dobTimeinfo = {}; // Initialize to zeros

    istringstream dateStream(dateStr);
    char delimiter;
    dateStream >> dobTimeinfo.tm_year >> delimiter >> dobTimeinfo.tm_mon >> delimiter >> dobTimeinfo.tm_mday;

    if (dateStream.fail() || delimiter != '-') {
        return false; // Invalid date format
    }

    // Adjust for struct tm representation (years since 1900, months 0-11)
    dobTimeinfo.tm_year -= 1900;
    dobTimeinfo.tm_mon -= 1;

    // Get the current time (timestamp)
    time_t now = time(nullptr);

    // Convert the timestamp to a local time struct tm
    tm currentTimeinfo;
    localtime_s(&currentTimeinfo, &now);

    // Calculate the age difference
    int age = currentTimeinfo.tm_year - dobTimeinfo.tm_year;
    if (currentTimeinfo.tm_mon <= dobTimeinfo.tm_mon ||
        currentTimeinfo.tm_mday < dobTimeinfo.tm_mday) {
        age--;
    }

    return age >= 18;
}

/*------------------------------------------------------------------------------------------------------------------------*/
/*-----------------------------------------------Trader_IO class functions------------------------------------------------*/


Trader Trader_IO::readTraderFromTerminal()
{

    string traderid = "", firstname = "", lastname = "", email = "", password = "", phoneNumber = "", dateOfBirth = "";

    traderid = generateUUID();

    firstname = Trader_IO::readName("Enter FirstName: ");

    lastname = Trader_IO::readName("Enter LastName: ");

    email = Trader_IO::readEmail(true);

    password = Trader_IO::readPasswords();

    phoneNumber = Trader_IO::readPhoneNumber();

    dateOfBirth = Trader_IO::readDateOfbirth();

    return Trader(traderid, firstname, lastname, email, password, phoneNumber, dateOfBirth);
}

string Trader_IO::readDateOfbirth()
{
    string dateStr;
    cout << "Enter your date of birth (YYYY-MM-DD): ";
    cin >> dateStr;

    // Check if the date format is correct
    while (!isValidDateFormat(dateStr) || !isValidDate(dateStr) || !isOver18YearsOld(dateStr)) {
        if (!isValidDateFormat(dateStr))
            cout << "Invalid date format. Please enter again (YYYY-MM-DD): " << endl;
        else if (!isValidDate(dateStr))
            cout << "Incorrect date. Please enter again (YYYY-MM-DD): " << endl;
        else
            cout << "You must be at least 18 years old" << endl;
        cin >> dateStr;
    }

    return dateStr;
}

string Trader_IO::readEmail(bool createAccount)
{
    string email_1, email_2;

    cout << "Enter your Email Address :" << endl;
    cin >> email_1;

    // Check if the email format is correct
    bool EmailExists = false;
    while (!isValidEmailFormat(email_1) || (createAccount && (EmailExists = Trader_DB::traderEmailExistsinDB(email_1))))
    {
        if (createAccount && EmailExists)
            cout << "Trader with the same email address already exists \n"
            "Please Try with another email address : " << endl;
        else
            cout << "Invalid email format. Please enter again: " << endl;

        cin >> email_1;

    }

    if (createAccount)
    {
        cout << "Confirm your Email Address :" << endl;
        cin >> email_2;

        // Check if the email format is correct
        while (!isValidEmailFormat(email_2) && email_1 != email_2) {
            cout << "In correct email address, please re-enter it again: " << endl;
            cin >> email_2;
        }
    }
    return email_1;
}

string Trader_IO::readName(const string& prompt)
{
    string Name;

    cout << prompt << endl;
    cin >> Name;

    // Check if the name is empty or contains only spaces
    while (Name.empty() || Name.find_first_not_of(' ') == string::npos) {
        cout << "Name cannot be empty or contain only spaces. Please enter again: " << endl;
        cin >> Name;
    }

    // Check if the name contains only alphabetic characters
    bool isValid = true;
    for (char c : Name) {
        if (!isalpha(c) && !isspace(c)) { // Allow spaces as separators
            isValid = false;
            break;
        }
    }

    while (!isValid) {
        cout << "Invalid Name. Please use only alphabetic characters: " << endl;
        cin >> Name;

        isValid = true;
        for (char c : Name) {
            if (!isalpha(c) && !isspace(c)) {
                isValid = false;
                break;
            }
        }
    }

    return removeRedundantSpaces(Name);
}

string Trader_IO::readPasswords()
{
    string password1;
    string password2;

    do {
        password1 = readSinglePassword("Enter your Password: ");
        if (!isValidPassword(password1)) {
            cout << "Invalid Password! Password should have a minimum length of 8 characters, "
                "and contain at least one capital letter and one special character.\n";
        }
    } while (!isValidPassword(password1));

    do {
        password2 = readSinglePassword("Confirm your Password: ");
        if (password1 != password2) {
            cout << "Passwords do not match. Please try again.\n";
        }
    } while (password1 != password2);

    return password1;
}


string Trader_IO::readPhoneNumber()
{
    string phoneNumber;
    cout << "Enter your Phone Number (including country indicator + or 00): " << endl;
    cin >> phoneNumber;

    // Check if the phone number is not empty
    while (phoneNumber.empty())
    {
        cout << "Phone Number cannot be empty. Please enter again: " << endl;
        cin >> phoneNumber;
    }

    // Check if the phone number contains only digits and has the country indicator
    bool PhoneExists = false;
    while (!isValidPhoneNumber(phoneNumber) || (PhoneExists = Trader_DB::traderPhoneExistsinDB(phoneNumber)))
    {
        if (PhoneExists)
            cout << "Trader with the same Phone number already exists\n"
            "Please Try with another phone number : " << endl;
        else
            cout << "Invalid Phone Number. Please enter again (including country indicator + or 00): " << endl;
        cin >> phoneNumber;
    }

    // Additional checks for phone number format or length can be added here

    return phoneNumber;
}

string Trader_IO::readSinglePassword(const string& prompt)
{
    string password;
    cout << prompt << endl;

    char ch;
    while ((ch = _getch()) != '\r') { // Read characters until Enter (Enter is represented by carriage return '\r')
        if (ch == '\b') { // Handle Backspace
            if (!password.empty()) {
                cout << "\b \b"; // Move the cursor back, print a space to overwrite the last character, move the cursor back again
                password.pop_back();
            }
        }
        else {
            cout << '*'; // Display '*' instead of the actual character
            password.push_back(ch);
        }
    }

    cout << endl;

    return password;

}
