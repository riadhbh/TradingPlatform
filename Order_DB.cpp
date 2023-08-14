#include "Order_DB.hpp"
#include <cppconn/prepared_statement.h>
#include "TRADINGPLATFORM_DEF.hpp"
#include "MySQLConnector.hpp"

void Order_DB::createOrder(const Order& o)
{
    try
    {
        sql::PreparedStatement* pstmt = nullptr;
        string query = "INSERT " + string(ORDER_ENTITY) +
            " Orders (OrderID, TraderID, ISINCode, OrderType, Qty, RemainingQty, Price, TimeStamp) VALUES (?, ?, ?, ?, ?, ?, ?, ?)";

        pstmt = MySQLConnector::getSQLConnection()->prepareStatement(query);

        pstmt->setString(1, o.getOrderID());
        pstmt->setString(2, o.getTraderID());
        pstmt->setString(3, o.getISINCode());
        pstmt->setString(4, (o.getOrderType() == BUY)?"Buy":"Sell");
        pstmt->setUInt(5, o.getQty());
        pstmt->setUInt(6, o.getRemainingQty());
        pstmt->setDouble(7, o.getPrice());
        pstmt->setUInt64(8, o.getTimeStamp());

        pstmt->executeQuery();
        cout << "Trader account successfully created !" << endl;
    }
    catch (sql::SQLException& e)
    {
        cerr << "SQL Exception: " << e.what() << endl;
        cerr << "Failed to insert trader into the database." << endl;
    }
}

Order Order_DB::loadOrderfromDB(string orderID)
{
    Order o("", "", "", BUY, 0, 0, 0, 0);
    try
    {

        std::string query = "select traderID, ISINCode, OrderType, Qty, RemainingQty, price, TimeStamp from " + string(ORDER_ENTITY) + " where orderID = ?";
        std::unique_ptr<sql::PreparedStatement> pstmt(MySQLConnector::getSQLConnection()->prepareStatement(query));

        pstmt->setString(1, orderID);

        std::unique_ptr<sql::ResultSet> res(pstmt->executeQuery());

        if (res->next()) {
            o.setOrderID(orderID);
            o.setTraderID(res->getString(1));
            o.setISINCode(res->getString(2));
            o.setOrderType(res->getString(3) == "Buy" ? BUY:SELL);
            o.setQty(res->getUInt(4));
            o.setRemainingQty(res->getUInt(5));
            o.setPrice(res->getDouble(6));
            o.setTimeStamp(res->getUInt64(7));
        }
    }
    catch (sql::SQLException& e)
    {
        cerr << "SQL Exception: " << e.what() << endl;
        return o;
    }

    return o;
}

vector<Order> Order_DB::loadTraderOrdersfromDB(const string& traderid)
{
    vector<Order> result;
    try
    {

        std::string query = "select orderID, ISINCode, OrderType, Qty, RemainingQty, price, TimeStamp from " + string(ORDER_ENTITY) + " where traderID = ?";
        std::unique_ptr<sql::PreparedStatement> pstmt(MySQLConnector::getSQLConnection()->prepareStatement(query));
        
        pstmt->setString(1, traderid);

        std::unique_ptr<sql::ResultSet> res(pstmt->executeQuery());

        while (res->next())
        {
            Order o("", "", "", BUY, 0, 0, 0, 0);

            o.setTraderID(traderid);
            o.setOrderID(res->getString(1));
            o.setISINCode(res->getString(2));
            o.setOrderType(res->getString(3) == "Buy" ? BUY : SELL);
            o.setQty(res->getUInt(4));
            o.setRemainingQty(res->getUInt(5));
            o.setPrice(res->getDouble(6));
            o.setTimeStamp(res->getUInt64(7));

            result.push_back(o);
        }
    }
    catch (sql::SQLException& e)
    {
        cerr << "SQL Exception: " << e.what() << endl;
        return result;
    }

    return result;
}
