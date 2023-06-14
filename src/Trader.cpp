/**
 * Trader.hpp
 * Contains trader details
 * 14-06-2023:MRBH:creation
 */


#include "Trader.hpp"

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
Trader::Trader(string TraderID, string FirstName, string LastName, string Email, string Password, string PhoneNumber, time_t DateOfBirth,string VATCode) {

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