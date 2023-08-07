/**
 * Trader.hpp
 * Contains trader details
 * 14-06-2023:MRBH:creation
 */

#pragma once
#include <ctime>
#include <string>
#include "Order.hpp"
#include <vector>

class Trader
{
public:

    Trader() = delete;

    /**
     * @param TraderID
     * @param FirstName
     * @param LastName
     * @param Email
     * @param Password
     * @param PhoneNumber
     * @param DateOfBirth
     */

    Trader(string TraderID, string FirstName, string LastName, string Email, string Password, string PhoneNumber, string DateOfBirth, bool is_admin = false, bool is_active = true);
    virtual ~Trader();
    /**
    * 
     * @param instumentID
     * @param Qty
     */
    void Buy(string instumentID, unsigned int Qty);

    /**
     * @param instumentID
     * @param Qty
     */
    void Sell(string instumentID, unsigned int Qty);

    /**
     * @param timestamp
     */
    void ViewOrderBook(time_t timestamp);

    // Getters
    string getTraderID() const;
    string getFirstName() const;
    string getLastName() const;
    string getEmail() const;
    string getPassword() const;
    string getPhoneNumber() const;
    string getDateOfBirth() const;
    bool isAdmin() const;

    // Setters
    void setTraderID(const string& id);
    void setFirstName(const string& firstName);
    void setLastName(const string& lastName);
    void setEmail(const string& email);
    void setPassword(const string& password);
    void setPhoneNumber(const string& phoneNumber);
    void setDateOfBirth(const string& dateOfBirth);
    void setAdmin(bool new_admin_status);

    // Friend function to overload the << operator
    friend ostream& operator<<(ostream& out, const Trader& trader);

    // Define the != operator as a member function
    bool operator!=(const Trader& t) const;

private:
    string TraderID;
    string FirstName;
    string LastName;
    string Email;
    string Password;
    string PhoneNumber;
    string DateOfBirth;
    bool is_active;
    bool is_admin;
};

