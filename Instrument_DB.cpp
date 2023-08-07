#include "Instrument_DB.hpp"
#include "MySQLConnector.hpp"
#include "TRADINGPLATFORM_DEF.hpp"
#include <cppconn/prepared_statement.h>

void Instrument_DB::createInstrument(const Instrument& i)
{
    try
    {
        sql::PreparedStatement* pstmt = nullptr;

        pstmt = MySQLConnector::getSQLConnection()->prepareStatement("INSERT INTO " + string(INSTRUMENT_ENTITY) + " (ISINCode, Name, Quantity, StrikePrice) VALUES (?, ?, ?, ?, ?, ?, ?, ?)");

        pstmt->setString(1, i.getISINCode());
        pstmt->setString(2, i.getName());
        pstmt->setUInt(3, i.getQuantity());
        pstmt->setDouble(4, i.getStrikePrice());

        pstmt->executeQuery();
        cout << "Instrument successfully added !" << endl;
    }
    catch (sql::SQLException& e)
    {
        cerr << "SQL Exception: " << e.what() << endl;
        cerr << "Failed to insert Instrument into the database." << endl;
    }
}

Instrument Instrument_DB::LoadInstrumentfromDB(string ISINCode)
{
    Instrument i("", "", 0, 0.0, true);
    try
    {

        std::string query = "select Name, Quantity, SrtrikePrice, is_active from " + string(TRADER_ENTITY) + " where ISINCode = ?";
        std::unique_ptr<sql::PreparedStatement> pstmt(MySQLConnector::getSQLConnection()->prepareStatement(query));

        pstmt->setString(1, ISINCode);
        std::unique_ptr<sql::ResultSet> res(pstmt->executeQuery());

        if (res->next()) 
        {
            i.setISINCode(ISINCode);
            i.setName(res->getString(1));
            i.setQuantity(res->getUInt(2));
            i.setStrikePrice(res->getDouble(3));
        }
    }
    catch (sql::SQLException& e)
    {
        cerr << "SQL Exception: " << e.what() << endl;
        return i;
    }

    return i;
}

void Instrument_DB::updateInstrument(const Instrument& i)
{
    try
    {

        std::string query = "update " + string(INSTRUMENT_ENTITY) + " set Name = ?, Quantity = ?, StrikePrice = ? WHERE ISINCode = ?";
        std::unique_ptr<sql::PreparedStatement> pstmt(MySQLConnector::getSQLConnection()->prepareStatement(query));

        pstmt->setString(1, i.getName());
        pstmt->setUInt(2, i.getQuantity());
        pstmt->setDouble(3, i.getStrikePrice());
        pstmt->setString(4, i.getISINCode());

        pstmt->executeQuery();

        cout << "Instrument successfully updated!" << endl;
    }
    catch (sql::SQLException& e)
    {
        cerr << "SQL Exception: " << e.what() << endl;
    }
}

void Instrument_DB::deleteInstrument(const string& ISINcode)
{
    try
    {

        std::string query = "update " + string(INSTRUMENT_ENTITY) + " set is_active = false WHERE ISINCode = ?";
        std::unique_ptr<sql::PreparedStatement> pstmt(MySQLConnector::getSQLConnection()->prepareStatement(query));
        pstmt->setString(1, ISINcode);
        pstmt->executeQuery();
    }
    catch (sql::SQLException& e)
    {
        cerr << "SQL Exception: " << e.what() << endl;
    }
}

bool Instrument_DB::ISINCodeExistsinDB(const std::string& ISINCode)
{
    try
    {

        std::string query = "SELECT COUNT(*) FROM " + string(INSTRUMENT_ENTITY) + " WHERE ISINCode = ?";
        std::unique_ptr<sql::PreparedStatement> pstmt(MySQLConnector::getSQLConnection()->prepareStatement(query));

        pstmt->setString(1, ISINCode);

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
