/**
 * Instrument.cpp
 * Contains Instrument details
 * 14-06-2023:MRBH:creation
 */


#include "Instrument.hpp"

 /**
  * Instrument implementation
  */


  /**
   * @param ISINCode
   * @param Name
   * @param Quantity
   * @param ExpiryDate
   * @param StrikePrice
   */
Instrument::Instrument(string ISINCode, string Name, unsigned int Quantity, double StrikePrice, bool isActive):
ISINCode(ISINCode), Name(Name), Quantity(Quantity), StrikePrice(StrikePrice), is_active(is_active)
{
}

void Instrument::setISINCode(string ISINcode)
{
    ISINCode = ISINcode;
}

/**
 * @param name
 */
void Instrument::setName(string name)
{
    Name = name;
}

/**
 * @param qty
 */
void Instrument::setQuantity(unsigned int qty) 
{
    Quantity = qty;
}

/**
 * @param price
 */
void Instrument::setStrikePrice(double price) 
{
    StrikePrice = price;
}

void Instrument::setActive(bool status)
{
    is_active = status;
}

string Instrument::getISINCode() const
{
    return ISINCode;
}

string Instrument::getName() const
{
    return Name;
}

unsigned int Instrument::getQuantity() const{

    return Quantity;
}

double Instrument::getStrikePrice() const
{
    return StrikePrice;
}

bool Instrument::isActive() const
{
    return is_active;
}
