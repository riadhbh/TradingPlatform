
#include "Trader_DB.hpp"
#include <cppconn/prepared_statement.h>
#include "TRADINGPLATFORM_DEF.hpp"
#include "MySQLConnector.hpp"

bool Trader_DB::login(string mail, string password)
{
    try
    {

        std::string query = "select count(*) from " + string(TRADER_ENTITY) + " where email like ? and password like ?";
        std::unique_ptr<sql::PreparedStatement> pstmt(MySQLConnector::getSQLConnection()->prepareStatement(query));

        pstmt->setString(1, mail);
        pstmt->setString(2, password);

        std::unique_ptr<sql::ResultSet> res(pstmt->executeQuery());

        if (res->next()) {
            int count = res->getInt(1);
            return count == 1;
        }
    }
    catch (sql::SQLException& e)
    {
        cerr << "SQL Exception: " << e.what() << endl;
        return false;
    }

    return false;
}

void Trader_DB::createAccount(const Trader& t)
{
    try
    {
        sql::PreparedStatement* pstmt = nullptr;

        pstmt = MySQLConnector::getSQLConnection()->prepareStatement("INSERT INTO " + string(TRADER_ENTITY) + " (TraderID, FirstName, LastName, Email, Password, PhoneNumber, DateOfBirth) VALUES (?, ?, ?, ?, ?, ?, ?)");

        pstmt->setString(1, t.getTraderID());
        pstmt->setString(2, t.getFirstName());
        pstmt->setString(3, t.getLastName());
        pstmt->setString(4, t.getEmail());
        pstmt->setString(5, t.getPassword());
        pstmt->setString(6, t.getPhoneNumber());
        pstmt->setString(7, t.getDateOfBirth());

        pstmt->executeQuery();
        cout << "Trader inserted successfully into the database!" << endl;
    }
    catch (sql::SQLException& e) 
    {
        cerr << "SQL Exception: " << e.what() << endl;
        cout << "Failed to insert trader into the database." << endl;
    }
}

void Trader_DB::updateAccount(const Trader&)
{
}

void Trader_DB::deleteAccount(const string&)
{
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
    }

    return false;
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
    }
    return false;
}