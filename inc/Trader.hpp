/**
 * Trader.hpp
 * Contains trader details
 * 14-06-2023:MRBH:creation
 */


#ifndef _TRADER_HPP
#define _TRADER_HPP

#include "Organizationtrader.hpp"
#include <ctime>
#include <string>
#include "Order.hpp"
#include <vector>

using namespace std;

class Trader {
public: 
Trader()=delete;

/**
 * @param TraderID
 * @param FirstName
 * @param LastName
 * @param Email
 * @param Password
 * @param PhoneNumber
 * @param DateOfBirth
 */
Trader(string TraderID, string FirstName, string LastName, string Email, string Password, string PhoneNumber, time_t DateOfBirth,string VATCode);
virtual ~Trader();
/**
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
private: 
    string TraderID;
    string FirstName;
    string LastName;
    string Email;
    string Password;
    string PhoneNumber;
    time_t DateOfBirth;
    string VATCode;
    vector<Order> OrderBook;
};

#endif //_TRADER_HPP