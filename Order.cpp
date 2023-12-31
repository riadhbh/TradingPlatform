/**
 * Order.hpp
 * Contains order details for each instument and trader
 * 14-06-2023:MRBH:creation
 */


#include "Order.hpp"
#include<iostream>
 /**
  * Order implementation
  */


  /**
   * @param OrderID
   * @param TraderID
   * @param ISINCode
   * @param OrderType
   * @param Qty
   * @param Price
   * @param TimeStamp
   */
Order::Order(string OrderID, string TraderID, string ISINCode, ordertype OrderType, unsigned int Qty, unsigned int RemainingQty, double price, time_t TimeStamp, ExecStatus execSatus)
    :OrderID(OrderID), TraderID(TraderID), ISINCode(ISINCode), OrderType(OrderType), Qty(Qty), RemainingQty(RemainingQty), Price(price), TimeStamp(TimeStamp), execSatus(execSatus)
{
}

// Getters
std::string Order::getOrderID() const
{
    return OrderID;
}

std::string Order::getTraderID() const
{
    return TraderID;
}

std::string Order::getISINCode() const
{
    return ISINCode;
}

ordertype Order::getOrderType() const
{
    return OrderType;
}

unsigned int Order::getQty() const
{
    return Qty;
}

unsigned int Order::getRemainingQty() const
{
    return RemainingQty;
}

double Order::getPrice() const
{
    return Price;
}

time_t Order::getTimeStamp() const
{
    return TimeStamp;
}

ExecStatus Order::getExecStatus() const
{
    return execSatus;
}

// Setters
void Order::setOrderID(const std::string& newOrderID)
{
    OrderID = newOrderID;
}

void Order::setTraderID(const std::string& newTraderID)
{
    TraderID = newTraderID;
}

void Order::setISINCode(const std::string& newISINCode)
{
    ISINCode = newISINCode;
}

void Order::setOrderType(ordertype newOrderType)
{
    OrderType = newOrderType;
}

void Order::setQty(unsigned int newQty)
{
    Qty = newQty;
}

void Order::setRemainingQty(unsigned int newRemainingQty)
{
    RemainingQty = newRemainingQty;
}

void Order::setPrice(double newPrice)
{
    Price = newPrice;
}

void Order::setTimeStamp(time_t newTimeStamp)
{
    TimeStamp = newTimeStamp;
}

void Order::setExecStatus(ExecStatus newExecStatus)
{
    execSatus = newExecStatus;
}

bool Order::operator==(const Order& o) const
{
    return
        (
            o.getOrderID() == OrderID &&
            o.getTraderID() == TraderID &&
            o.getISINCode() == ISINCode &&
            o.getOrderType() == OrderType &&
            o.getPrice() == Price &&
            o.getQty() == Qty &&
            o.getRemainingQty() == RemainingQty &&
            o.getTimeStamp() == TimeStamp &&
            o.getExecStatus() == execSatus
        );
}

bool Order::operator!=(const Order& o) const
{
    return
        (
            o.getOrderID() != OrderID ||
            o.getTraderID() != TraderID ||
            o.getISINCode() != ISINCode ||
            o.getOrderType() != OrderType ||
            o.getPrice() != Price ||
            o.getQty() != Qty ||
            o.getRemainingQty() != RemainingQty ||
            o.getTimeStamp() != TimeStamp ||
            o.getExecStatus() != execSatus
         );
}

string Order::execStatusToString(const ExecStatus es)
{
    if (es == X)
        return "X";
    else if (es == TX)
        return "TX";
    else
        return "X0";
}

ExecStatus Order::stringToExecStatus(const string str)
{
    if (str == "X")
        return X;
    else if (str == "TX")
        return TX;
    else
        return X0;
}

// Definition of the << operator overload
std::ostream& operator<<(std::ostream& os, const Order& order)
{
    os << "OrderID: " << order.OrderID << " | ";
    os << "TraderID: " << order.TraderID << " | ";
    os << "ISINCode: " << order.ISINCode << " | ";
    os << "OrderType: " << ((order.OrderType == BUY) ? "BUY":"SELL") << " | ";
    os << "Qty: " << order.Qty << " | ";
    os << "RemainingQty: " << order.RemainingQty << " | ";
    os << "Price: " << order.Price << " | ";
    os << "TimeStamp: " << order.TimeStamp << " | ";
    os << "ExecStatus: " << order.execSatus;
    return os;
}