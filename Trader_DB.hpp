#pragma once
#include <string>
#include "Trader.hpp"
using namespace std;
class Trader_DB
{
	public:
		//DB CRUDS
		static bool login(string, string);
		static void createAccount(const Trader&);
		static void updateAccount(const Trader&);
		static void deleteAccount(const string&);
		static bool traderEmailExistsinDB(const std::string& email);
		static bool traderPhoneExistsinDB(const std::string& phoneNumber);
};

