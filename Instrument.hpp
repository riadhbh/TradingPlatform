/**
 * Instrument.hpp
 * Contains Instrument details
 * 14-06-2023:MRBH:creation
 */
#pragma once
#include <iostream>
#include <ctime>
#include <string>
#include "Order.hpp"
using namespace std;

class Instrument
{
public:
    /**
     * @param ISINCode
     * @param Name
     * @param Quantity
     * @param ExpiryDate
     * @param StrikePrice
     */
    Instrument() = delete;
    Instrument(string ISINCode, string Name, unsigned int Quantity, double StrikePrice, bool is_active = true);

    //Setters
    /**
     * @param name
     */
    void setISINCode(string ISICode);
    void setName(string name);

    /**
     * @param qty
     */
    void setQuantity(unsigned int qty);

    /**
     * @param price
     */
    void setStrikePrice(double price);

    void setActive(bool status);

    // Getters
    string getISINCode() const;
    string getName() const;
    unsigned int getQuantity() const;
    double getStrikePrice() const;
    bool isActive() const;

    void executeOrder(Order& order);

    // Friend function to overload the << operator
    friend ostream& operator<<(ostream& out, const Instrument& inst);

    // Define the == operator as a member function
    bool operator==(const Instrument& i) const;

    // Define the != operator as a member function
    bool operator!=(const Instrument& i) const;

private:
    string ISINCode;
    string Name;
    unsigned int Quantity;
    double StrikePrice;
    bool is_active;
};

