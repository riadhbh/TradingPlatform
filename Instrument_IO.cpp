#include "Instrument_IO.hpp"
#include <iostream>
#include <string>
#include <regex>

bool isValidISIN(const std::string& isin) {
    // ISIN code should be 12 characters long
    if (isin.length() != 12) {
        return false;
    }

    // ISIN code should contain only uppercase letters and digits
    for (char c : isin) {
        if (!std::isalnum(c) || std::islower(c)) {
            return false;
        }
    }

    return true;
}


string Instrument_IO::readISINCode() {
    std::string isinCode;
    while (true) {
        std::cout << "Enter the ISIN code: ";
        std::cin >> isinCode;

        if (isValidISIN(isinCode)) {
            break; // Exit the loop if the entered ISIN is valid
        }
        else {
            std::cout << "Invalid ISIN code. Please enter a valid 12-character code consisting of uppercase letters and digits." << std::endl;
        }
    }
    return isinCode;
}

string Instrument_IO::readInstrumentName(){
    string instrument_name = "";

    while(true){
        
        cout << "Enter the instrument name: ";
        cin >> instrument_name;
        if(instrument_name.length() > 0) break;
        else cout << "Instrument name cannot be empty!" << endl;
    }
    

    return instrument_name;
}

double Instrument_IO::readStrikePrice(){
    
    double instrument_strike_price = 0.0;

    while(true){
        
        cout << "Enter the instrument strike price: ";
        cin >> instrument_strike_price;
        if(instrument_strike_price > 0) break;
        else cout << "Instrument strike price cannot be zero or negative!" << endl;
    }
    

    return instrument_strike_price;
}

int Instrument_IO::readQuantity(){
    
    int instrument_quantity = 0;

    while(true){
        
        cout << "Enter the instrument quantity: ";
        cin >> instrument_quantity;
        if(instrument_quantity > 0) break;
        else cout << "Instrument quantity cannot be zero or negative!" << endl;
    }
    

    return instrument_quantity;
}

bool Instrument_IO::readIsActive(){
    
    char ch='*';
    cout << "Is the instrument active for trading(Y/N): ";
    cin>>ch;
    ch = tolower(ch);

    while (ch != 'n' && ch != 'y')
    {
        cout << "Invalid choice" << endl;
        cout << "Is the instrument active for trading(Y/N): ";
        cin >> ch;
        ch = tolower(ch);
    }

    return (ch == 'y');
}

Instrument Instrument_IO::readInstrumentFromTerminal()
{
    
     string isincode = "", instrumentname = "";
     double strikeprice = 0.0;
     int quantity = 0;
     bool active = false;

     isincode = Instrument_IO::readISINCode();
     instrumentname = Instrument_IO::readInstrumentName();
     strikeprice = Instrument_IO::readStrikePrice();
     quantity = Instrument_IO::readQuantity();
     active = Instrument_IO::readIsActive();

	return Instrument(isincode, instrumentname, quantity, strikeprice, active);
}
