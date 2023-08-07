
#include "Trader_DB.hpp"
#include <cppconn/prepared_statement.h>
#include "TRADINGPLATFORM_DEF.hpp"
#include "MySQLConnector.hpp"

string Trader_DB::login(string mail, string password)
{
    string traderID = "";
    try
    {

        std::string query = "select traderid from " + string(TRADER_ENTITY) + " where is_active = true and email like ? and password = ?";
        std::unique_ptr<sql::PreparedStatement> pstmt(MySQLConnector::getSQLConnection()->prepareStatement(query));

        pstmt->setString(1, mail);
        pstmt->setString(2, password);

        std::unique_ptr<sql::ResultSet> res(pstmt->executeQuery());

        if (res->next()) {
            traderID = res->getString(1);
        }
    }
    catch (sql::SQLException& e)
    {
        cerr << "SQL Exception: " << e.what() << endl;
        return "";
    }

    return traderID;
}

void Trader_DB::createTraderAccount(const Trader& t)
{
    try
    {
        sql::PreparedStatement* pstmt = nullptr;

        pstmt = MySQLConnector::getSQLConnection()->prepareStatement("INSERT INTO " + string(TRADER_ENTITY) + " (TraderID, FirstName, LastName, Email, Password, PhoneNumber, DateOfBirth, is_admin) VALUES (?, ?, ?, ?, ?, ?, ?, ?)");

        pstmt->setString(1, t.getTraderID());
        pstmt->setString(2, t.getFirstName());
        pstmt->setString(3, t.getLastName());
        pstmt->setString(4, t.getEmail());
        pstmt->setString(5, t.getPassword());
        pstmt->setString(6, t.getPhoneNumber());
        pstmt->setString(7, t.getDateOfBirth());
        pstmt->setBoolean(8, t.isAdmin());

        pstmt->executeQuery();
        cout << "Trader account successfully created !" << endl;
    }
    catch (sql::SQLException& e) 
    {
        cerr << "SQL Exception: " << e.what() << endl;
        cerr << "Failed to insert trader into the database." << endl;
    }
}

void Trader_DB::updateTraderAccount(const Trader& t)
{
    try
    {

        std::string query = "update " + string(TRADER_ENTITY) + " set email = ?, password = ?, phonenumber = ? WHERE traderid = ?";
        std::unique_ptr<sql::PreparedStatement> pstmt(MySQLConnector::getSQLConnection()->prepareStatement(query));

        pstmt->setString(1, t.getEmail());
        pstmt->setString(2, t.getPassword());
        pstmt->setString(3, t.getPhoneNumber());
        pstmt->setString(4, t.getTraderID());

        pstmt->executeQuery();

        cout << "Trader Account successfully updated!" << endl;
    }
    catch (sql::SQLException& e)
    {
        cerr << "SQL Exception: " << e.what() << endl;
    }
}

void Trader_DB::deleteTraderAccount(const string& traderID)
{
    try
    {

        std::string query = "update " + string(TRADER_ENTITY) + " set is_active = false WHERE traderid = ?";
        std::unique_ptr<sql::PreparedStatement> pstmt(MySQLConnector::getSQLConnection()->prepareStatement(query));
        pstmt->setString(1, traderID);
        pstmt->executeQuery();
    }
    catch (sql::SQLException& e)
    {
        cerr << "SQL Exception: " << e.what() << endl;
    }
}

bool Trader_DB::traderEmailExistsinDB(const std::string& email)
{
    try
    {

        std::string query = "SELECT COUNT(*) FROM " + string(TRADER_ENTITY) + " WHERE Email = ?";
        std::unique_ptr<sql::PreparedStatement> pstmt(MySQLConnector::getSQLConnection()->prepareStatement(query));

        pstmt->setString(1, email);

        std::unique_ptr<sql::ResultSet> res(pstmt->executeQuery());

        if (res->next()) 
        {
            int count = res->getInt(1);
            return count > 0;
        }
    }
    catch (sql::SQLException& e)
    {
        cerr << "SQL Exception: " << e.what() << endl;
        return false;
    }
}

bool Trader_DB::traderPhoneExistsinDB(const std::string& phoneNumber)
{
    try
    {

        std::string query = "SELECT COUNT(*) FROM " + string(TRADER_ENTITY) + " WHERE phonenumber = ?";
        std::unique_ptr<sql::PreparedStatement> pstmt(MySQLConnector::getSQLConnection()->prepareStatement(query));

        pstmt->setString(1, phoneNumber);

        std::unique_ptr<sql::ResultSet> res(pstmt->executeQuery());

        if (res->next()) {
            int count = res->getInt(1);
            return count > 0;
        }
    }
    catch (sql::SQLException& e)
    {
        cerr << "SQL Exception: " << e.what() << endl;
        return false;
    }
}

Trader Trader_DB::LoadTraderfromDB(string traderID) 
{
    Trader t ("", "", "", "", "", "", "");
    try
    {

        std::string query = "select firstname, lastname, email, password, phonenumber, dateofbirth, is_admin from " + string(TRADER_ENTITY) + " where traderid = ?";
        std::unique_ptr<sql::PreparedStatement> pstmt(MySQLConnector::getSQLConnection()->prepareStatement(query));

        pstmt->setString(1, traderID);

        std::unique_ptr<sql::ResultSet> res(pstmt->executeQuery());

        if (res->next()) {
            t.setTraderID(traderID);
            t.setFirstName(res->getString(1));
            t.setLastName(res->getString(2));
            t.setEmail(res->getString(3));
            t.setPassword(res->getString(4));
            t.setPhoneNumber(res->getString(5));
            t.setDateOfBirth(res->getString(6));
            t.setAdmin(res->getBoolean(7));
        }
    }
    catch (sql::SQLException& e)
    {
        cerr << "SQL Exception: " << e.what() << endl;
        return t;
    }

    return t;
}