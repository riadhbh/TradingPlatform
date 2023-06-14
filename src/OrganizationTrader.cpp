/**
 * OrganizationTrader.cpp
 * Contains organization trader details
 * 14-06-2023:MRBH:creation
 */


#include "OrganizationTrader.hpp"
#include "Instrument.hpp"
/**
 * OrganizationTrader implementation
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
OrganizationTrader::OrganizationTrader(string TraderID, string FirstName, string LastName, string Email, string Password, string PhoneNumber, time_t DateOfBirth, string VATCode, string OrganizationName) {

}

/**
 * @param InstrumentID
 * @param Name
 * @param Quantity
 * @param ExpiryDate
 * @param StrikePrice
 */
void OrganizationTrader::CreateInstrument(string InstrumentID, string Name, unsigned int Quantity, time_t ExpiryDate, double StrikePrice) {

}

/**
 * @param InstrID
 */
void OrganizationTrader::ModifyInstrument(string InstrID) {

}

/**
 * @param InstrID
 */
void OrganizationTrader::DeleteInstrument(string InstrID) {

}