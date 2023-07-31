/**
 * MySQLConnector.hpp
 * Contains organization trader details
 * 19-06-2023:MRBH:creation
 */
#pragma once
#include <mysql_connection.h>
using namespace sql::mysql;
class MySQLConnector
{
public:
	static sql::Connection* getSQLConnection();
};

