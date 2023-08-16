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
enum ExecStatus {X0, X, TX};//zero execusion, partial executed, Fully executed

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
        Order(string OrderID, string TraderID, string ISINCode, ordertype OrderType, unsigned int Qty, unsigned int RemainingQty, double price, time_t TimeStamp, ExecStatus execSatus = X0);
        
        // Getters
        std::string getOrderID() const;
        std::string getTraderID() const;
        std::string getISINCode() const;
        ordertype getOrderType() const;
        unsigned int getQty() const;
        unsigned int getRemainingQty() const;
        double getPrice() const;
        time_t getTimeStamp() const;
        ExecStatus getExecStatus() const;

        // Setters
        void setOrderID(const std::string& newOrderID);
        void setTraderID(const std::string& newTraderID);
        void setISINCode(const std::string& newISINCode);
        void setOrderType(ordertype newOrderType);
        void setQty(unsigned int newQty);
        void setRemainingQty(unsigned int newRemainingQty);
        void setPrice(double newPrice);
        void setTimeStamp(time_t newTimeStamp);
        void setExecStatus(ExecStatus newExecStatus);

        // Declaration of the << operator overload as a friend function
        friend std::ostream& operator<<(std::ostream& os, const Order& order);

        // Define the == operator as a member function
        bool operator==(const Order& o) const;

        // Define the != operator as a member function
        bool operator!=(const Order& o) const;

        static string execStatusToString(const ExecStatus es);
        static ExecStatus stringToExecStatus(const string str);
    private:
        string OrderID;
        string TraderID;
        string ISINCode;
        ordertype OrderType;
        ExecStatus execSatus;
        unsigned int Qty;
        unsigned int RemainingQty;
        double Price;
        time_t TimeStamp;
};

