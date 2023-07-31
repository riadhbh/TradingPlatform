/**
 * TRADINGPLATFORM_DEF.hpp
 * Contains usable definitions and constants
 * 26-07-2023:MRBH:creation
 */


#pragma once
#include <rpc.h>
#include <string>

/* MYSQL DEFS */
#define MYSQL_HOST  "tcp://127.0.0.1:3306"
#define MYSQL_user  "root"
#define MYSQL_pass  "hunter21"
#define MYSQL_schema "tradingplatform"

#define TRADER_ENTITY     "trader"
#define INSTRUMENT_ENTITY "instrument"
#define ORDER_ENTITY      "order"

std::string generateUUID();
