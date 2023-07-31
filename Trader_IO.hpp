#pragma once
#include <string>
#include "Trader.hpp"
using namespace std;
class Trader_IO
{
public :
    //reading and checking Trader termnial input data
    static bool isValidDateFormat(const string&);
    static bool isOver18YearsOld(const string&);
    static bool isValidEmailFormat(const string&);
    static bool isValidPhoneNumber(const string& phoneNumber);
    static string removeRedundantSpaces(const string& str);
    static string readDateOfbirth();
    static string readEmail(bool createAccount = false);
    static string readSignlePassword(const string& prompt);
    static string readPasswords();
    static string readPhoneNumber();
    static string readName(const string& prompt);
    static Trader readTraderFromTerminal();
};