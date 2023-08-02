#pragma once
#include <string>
#include "Trader.hpp"
using namespace std;
class Trader_DB
{
	public:
		//DB CRUDS
		static string login(string, string);
		static void createTraderAccount(const Trader&);
		static void updateTraderAccount(const Trader&);
		static void deleteTraderAccount(const string&);
		static bool traderEmailExistsinDB(const std::string& email);
		static bool traderPhoneExistsinDB(const std::string& phoneNumber);
		static Trader LoadTraderfromDB(string traderID);
};

