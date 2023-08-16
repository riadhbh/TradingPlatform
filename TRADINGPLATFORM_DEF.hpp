/**
 * TRADINGPLATFORM_DEF.hpp
 * Contains usable definitions and constants
 * 26-07-2023:MRBH:creation
 */


#pragma once
#include <iostream>
#include <iomanip>
#include <random>
#include <sstream>
#include <string>

/* MYSQL DEFS */
#define MYSQL_HOST  "tcp://127.0.0.1:3306"
#define MYSQL_user  "root"
#define MYSQL_pass  "hunter21"
#define MYSQL_schema "tradingplatform"

#define TRADER_ENTITY     "trader"
#define INSTRUMENT_ENTITY "instrument"
#define ORDER_ENTITY      "orders"

/* Common functions */
std::string generateUUID();

template <typename T>
long long getIndex(const std::vector<T>& vec, T elem) {
    auto it = std::find_if(vec.begin(), vec.end(), [&elem](const T& e) 
        {
            return e == elem;
        });

    if (it != vec.end()) {
        return std::distance(vec.begin(), it);
    }

    return -1; // Not found
}