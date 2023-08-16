/**
 * Trader.hpp
 * Contains trader details
 * 14-06-2023:MRBH:creation
 */


#include "Trader.hpp"
#include <iostream>

 /**
  * Trader implementation
  */

  /**
   * @param TraderID
   * @param FirstName
   * @param LastName
   * @param Email
   * @param Password
   * @param PhoneNumber
   * @param DateOfBirth
   */
Trader::Trader(string TraderID, string FirstName, string LastName, string Email, string Password, string PhoneNumber, string DateOfBirth, bool is_admin, bool is_active):
TraderID(TraderID), FirstName(FirstName), LastName(LastName), Email(Email), Password(Password), PhoneNumber(PhoneNumber), DateOfBirth(DateOfBirth), is_active(is_active), is_admin(is_admin)
{

}

/**
 * @param instumentID
 * @param Qty
 */
void Trader::Buy(string instumentID, unsigned int Qty) {

}

/**
 * @param instumentID
 * @param Qty
 */
void Trader::Sell(string instumentID, unsigned int Qty) {

}

/**
 * @param timestamp
 */
void Trader::ViewOrderBook(time_t timestamp) {

}

Trader::~Trader() {

}


// Getters
string Trader::getTraderID() const
{
    return TraderID;
}
string Trader::getFirstName() const
{
    return FirstName;
}
string Trader::getLastName() const
{
    return LastName;
}
string Trader::getEmail() const
{
    return Email;
}
string Trader::getPassword() const
{
    return Password;
}
string Trader::getPhoneNumber() const
{
    return PhoneNumber;
}
string Trader::getDateOfBirth() const
{
    return DateOfBirth;
}
bool Trader::isAdmin() const 
{
    return is_admin;
}

// Setters
void Trader::setTraderID(const string& id)
{
    TraderID = id;
}
void Trader::setFirstName(const string& firstName)
{
    FirstName = firstName;
}
void Trader::setLastName(const string& lastName)
{
    LastName = lastName;
}
void Trader::setEmail(const string& email)
{
    Email = email;
}
void Trader::setPassword(const string& password)
{
    Password = password;
}
void Trader::setPhoneNumber(const string& phoneNumber)
{
    PhoneNumber = phoneNumber;
}
void Trader::setDateOfBirth(const string& dateOfBirth)
{
    DateOfBirth = dateOfBirth;
}

void Trader::setAdmin(bool new_admin_status) 
{
    is_admin = new_admin_status;
}

ostream& operator<<(ostream& out, const Trader& trader) {
    out << "TraderID: \n" << trader.TraderID <<endl
        << "FirstName: \n" << trader.FirstName << endl
        << "LastName: \n" << trader.LastName << endl
        << "Email: \n" << trader.Email << endl
        << "Password: \n" << "********" << endl
        << "PhoneNumber: \n" << trader.PhoneNumber << endl
        << "DateOfBirth: \n" << trader.DateOfBirth << endl;
    return out;
}

bool Trader::operator==(const Trader& t) const
{
    return (
        t.getTraderID() == TraderID &&
        t.getDateOfBirth() == DateOfBirth &&
        t.getFirstName() == FirstName &&
        t.getLastName() == LastName &&
        t.getEmail() == Email &&
        t.getPassword()  == Password &&
        t.getPhoneNumber() == PhoneNumber &&
        t.isAdmin() == is_admin
        );
}

bool Trader::operator!=(const Trader& t) const
{
    return (
            t.getTraderID() != TraderID ||
            t.getDateOfBirth() != DateOfBirth ||
            t.getFirstName() != FirstName ||
            t.getLastName() != LastName ||
            t.getEmail() != Email ||
            t.getPassword() != Password ||
            t.getPhoneNumber() != PhoneNumber ||
            t.isAdmin() != is_admin
        );
}