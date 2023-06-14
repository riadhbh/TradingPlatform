/**
 * Instrument.hpp
 * Contains Instrument details
 * 14-06-2023:MRBH:creation
 */


#ifndef _INSTRUMENT_HPP
#define _INSTRUMENT_HPP
#include <ctime>
#include <string>
using namespace std;
class Instrument {
public:  
/**
 * @param InstrumentID
 * @param Name
 * @param Quantity
 * @param ExpiryDate
 * @param StrikePrice
 */
Instrument()=delete;
Instrument(string InstrumentID, string Name, unsigned int Quantity, time_t ExpiryDate, double StrikePrice);
    
/**
 * @param name
 */
void setName(string name);
    
/**
 * @param qty
 */
void setQuantity(unsigned int qty);
    
/**
 * @param price
 */
void setStrikePrice(double price);
    
/**
 * @param date
 */
void setExpiryDate(time_t date);
    
unsigned int getQuantity();

private: 
    string InstrumentID;
    string Name;
    unsigned int Quantity;
    time_t ExpiryDate;
    double StrikePrice;
};

#endif //_INSTRUMENT_HPP