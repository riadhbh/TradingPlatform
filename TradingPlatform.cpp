/**
 * TradingPlatform.cpp
 * Contains the execution workflow
 * 14-06-2023:MRBH:creation
 */

#include "TradingPlatform.hpp"

#include "Instrument.hpp"
#include "Order.hpp"
#include "Trader.hpp"

#include <iostream>
#include "Trader_IO.hpp"
#include "Trader_DB.hpp"

using namespace std;



void TradingPlatform::CreateTraderAccount()
{
    cout << "***Create trader account***" << endl;
    Trader t = Trader_IO::readTraderFromTerminal();
    Trader_DB::createAccount(t);
}


void TradingPlatform::Login()
{
    cout << "***Login***" << endl;
    string email = "", password = "";
    bool connected = false;
    int i = 0;
    while (!connected && i<3)
    {
        i++;
        email = Trader_IO::readEmail(false);
        password = Trader_IO::readSignlePassword("Please Enter your Password :");
        connected = Trader_DB::login(email, password);
        if (!connected)
        {
            cout << "Invalid email or password" << endl;
        }
        email = "";
        password = "";
    }
    
    if(connected)
        cout << "Welcome !" << endl;
}


int main()
{

    cout << "Welcome to our trading platfrom" << endl;
    char c = '*';
    do
    {
        cout << "***Main Menu***" << endl;
        cout << "0) Exit" << endl;
        cout << "1) Login" << endl;
        cout << "2) Create account" << endl;
        cin >> c;

        switch (c)
        {
        case '0': exit(0); break;
        case '1': TradingPlatform::Login(); break;
        case '2': TradingPlatform::CreateTraderAccount();break;
        default: cout << "Invalid choice, please try again";
        }

    } while (c != '0');
    cout << "Shutting down ..." << endl;
    
    return 0;
}