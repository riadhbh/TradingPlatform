#pragma once
#include <string>
#include "Trader.hpp"
using namespace std;
class Trader_IO
{
public :
    //reading and checking Trader termnial input data
    static string readDateOfbirth();
    static string readEmail(bool createAccount = false);
    static string readSinglePassword(const string& prompt);
    static string readPasswords();
    static string readPhoneNumber();
    static string readName(const string& prompt);
    static Trader readTraderFromTerminal();
    static bool readStatus(const string& prompt);
};