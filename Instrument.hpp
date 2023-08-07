/**
 * Instrument.hpp
 * Contains Instrument details
 * 14-06-2023:MRBH:creation
 */
#pragma once
#include <ctime>
#include <string>
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


private:
    string ISINCode;
    string Name;
    unsigned int Quantity;
    double StrikePrice;
    bool is_active;
};

