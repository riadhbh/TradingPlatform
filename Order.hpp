/**
 * Order.hpp
 * Contains order details for each instument and trader
 * 14-06-2023:MRBH:creation
 */


#pragma once

#include <ctime>
#include <string>
using namespace std;

enum ordertype { BUY, SELL };

class Order
{
    public:

        /**
         * @param OrderID
         * @param TraderID
         * @param InstrumentID
         * @param OrderType
         * @param Qty
         * @param Price
         * @param TimeStamp
         */
        Order() = delete;
        Order(string OrderID, string TraderID, string InstrumentID, ordertype OrderType, double Qty, double price, time_t TimeStamp);
    private:
        string OrderID;
        string TraderID;
        string InstrumentID;
        ordertype OrderType;
        unsigned int Qty;
        double Price;
        time_t TimeStamp;
};

