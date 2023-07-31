/**
 * MySQLConnector.cpp
 * Contains organization trader details
 * 19-06-2023:MRBH:creation
 */

#include "MySQLConnector.hpp"
#include <memory>
#include <mutex>
#include <mysql_driver.h>
#include <cppconn/driver.h>
#include "TRADINGPLATFORM_DEF.hpp"
using namespace std;
mutex mutex_guard;
sql::Connection* MySQLConnector::getSQLConnection()
{
    mutex_guard.lock();
    static shared_ptr<sql::Connection> connection(nullptr);
    if (!connection)
    {
        sql::mysql::MySQL_Driver* driver = sql::mysql::get_mysql_driver_instance();
        connection.reset(driver->connect(MYSQL_HOST, MYSQL_user, MYSQL_pass));
        connection->setSchema(MYSQL_schema);
    }
    mutex_guard.unlock();
    return connection.get();
}