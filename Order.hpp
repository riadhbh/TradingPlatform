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
         * @param ISINCode
         * @param OrderType
         * @param Qty
         * @param Price
         * @param TimeStamp
         */
        Order() = delete;
        Order(string OrderID, string TraderID, string ISINCode, ordertype OrderType, unsigned int Qty, unsigned int RemainingQty, double price, time_t TimeStamp);
        
        // Getters
        std::string getOrderID() const;
        std::string getTraderID() const;
        std::string getISINCode() const;
        ordertype getOrderType() const;
        unsigned int getQty() const;
        unsigned int getRemainingQty() const;
        double getPrice() const;
        time_t getTimeStamp() const;

        // Setters
        void setOrderID(const std::string& newOrderID);
        void setTraderID(const std::string& newTraderID);
        void setISINCode(const std::string& newISINCode);
        void setOrderType(ordertype newOrderType);
        void setQty(unsigned int newQty);
        void setRemainingQty(unsigned int newRemainingQty);
        void setPrice(double newPrice);
        void setTimeStamp(time_t newTimeStamp);

        // Declaration of the << operator overload as a friend function
        friend std::ostream& operator<<(std::ostream& os, const Order& order);

    private:
        string OrderID;
        string TraderID;
        string ISINCode;
        ordertype OrderType;
        unsigned int Qty;
        unsigned int RemainingQty;
        double Price;
        time_t TimeStamp;
};

