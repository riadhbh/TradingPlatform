/**
 * OrganizationTrader.hpp
 * Contains organization trader details
 * 14-06-2023:MRBH:creation
 */


#ifndef _ORGANIZATION_TRADER_HPP
#define _ORGANIZATION_TRADER_HPP

#include "Trader.hpp"
#include <ctime>
#include <string>
using namespace std;

class OrganizationTrader: public Trader {

public: 

OrganizationTrader()=delete;

/**
 * @param TraderID
 * @param FirstName
 * @param LastName
 * @param Email
 * @param Password
 * @param PhoneNumber
 * @param DateOfBirth
 */
OrganizationTrader(string TraderID, string FirstName, string LastName, string Email, string Password, string PhoneNumber, time_t DateOfBirth, string VATCode, string OrganizationName);
    
/**
 * @param InstrumentID
 * @param Name
 * @param Quantity
 * @param ExpiryDate
 * @param StrikePrice
 */
void CreateInstrument(string InstrumentID, string Name, unsigned int Quantity, time_t ExpiryDate, double StrikePrice);
    
/**
 * @param InstrID
 */
void ModifyInstrument(string InstrID);
    
/**
 * @param InstrID
 */
void DeleteInstrument(string InstrID);

private: 
    string OrganizationName;
};

#endif //_ORGANIZATION_TRADER_HPP