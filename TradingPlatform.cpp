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

static Trader currentTrader("", "", "", "", "", "", "");

void TradingPlatform::UpdateTraderMenu()
{
    cout << "Update trader account information" << endl;
    char c = '*';
    string cPassword="";
    try {
        Trader tmp_Trader = currentTrader;
        do
        {
            cout << "0) Back to previous menu" << endl;
            cout << "1) Update email" << endl;
            cout << "2) Update phone number" << endl;
            cout << "3) Update password" << endl;
            cin >> c;
            switch (c)
            {
            case '0': break;
            case '1': tmp_Trader.setEmail(Trader_IO::readEmail(true)); break;
            case '2': tmp_Trader.setPhoneNumber(Trader_IO::readPhoneNumber()); break;
            case '3': cPassword = Trader_IO::readSinglePassword("Enter the current password : ");   
                        if (cPassword != tmp_Trader.getPassword())
                        {
                            cout << "Password incorrect please try again !" << endl;
                        }
                        else
                        {
                            tmp_Trader.setPassword(Trader_IO::readPasswords()); break;
                        }
            default: cout << "Invalid choice, please try again" << endl;
            }

            if(tmp_Trader != currentTrader)
            { 
                Trader_DB::updateTraderAccount(tmp_Trader);
                currentTrader = tmp_Trader;
                cout << currentTrader;
            }
            

        } while (c != '0');
    }
    catch(exception & e)
    { 
        cerr << e.what() << endl;
    }
}

void TradingPlatform::DeleteTraderMenu()
{

    char c = '*';
    string cPassword = "";
    try {
        do
        {
            cout << "Do you want to delete your Account (Y/N) ?" << endl;
            cin >> c;

            if (c != '0' && tolower(c) != 'y' && tolower(c) != 'n')
                cout << "Invalid choice please chose either Y or N, otherwise 0 to back to the previous menu" << endl;

            if (tolower(c) == 'y')
            {

                cPassword = Trader_IO::readSinglePassword("Enter the current password : ");
                if (cPassword != currentTrader.getPassword())
                {
                    cout << "Password incorrect please try again !" << endl;
                }
                else
                {
                    Trader_DB::deleteTraderAccount(currentTrader.getTraderID());
                    currentTrader = Trader("", "", "", "", "", "", "");
                }
                
            }

        } while (c != '0' && tolower(c)!='y' && tolower(c) != 'n');
    }
    catch (exception& e)
    {
        cerr << e.what() << endl;
    }

}

void TradingPlatform::TraderMenu()
{
    cout << "*** Welcome " << currentTrader.getFirstName() << " ! ***" << endl;
    char c = '*';
    do
    {
        cout << "0) Logout" << endl;
        cout << "1) View account information" << endl;
        cout << "2) View orderbook" << endl;
        cout << "3) Delete account" << endl;
        cin >> c;
        switch (c)
        {
        case '0': cout << "Logout..." << endl;
            currentTrader = Trader("", "", "", "", "", "", "");
            ; break;
        case '1': cout<<currentTrader; 
                  UpdateTraderMenu();
                  break;
        case '2': cout << "View orderbook" << endl; break;
        case '3': DeleteTraderMenu();
                  c = '0';//logout
                  break;
        default: cout << "Invalid choice, please try again"<<endl;
        }

     } while (c != '0');
}

void TradingPlatform::CreateTraderAccountMenu()
{
    cout << "***Create trader account***" << endl;
    Trader t = Trader_IO::readTraderFromTerminal();
    Trader_DB::createTraderAccount(t);
}


void TradingPlatform::LoginMenu()
{
    cout << "***Login***" << endl;
    string email = "", password = "";
    string traderID = "";
    int i = 0;
    while (traderID.empty() && i<3)
    {
        i++;
        email = Trader_IO::readEmail(false);
        password = Trader_IO::readSinglePassword("Please Enter your Password :");
        traderID = Trader_DB::login(email, password);
        if (traderID.empty())
        {
            cout << "Invalid email or password" << endl;
        }
        email = "";
        password = "";
    }
    
    if (!traderID.empty())
    {
        currentTrader = Trader_DB::LoadTraderfromDB(traderID);
        TradingPlatform::TraderMenu();
    }
        
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
        case '1': TradingPlatform::LoginMenu(); break;
        case '2': TradingPlatform::CreateTraderAccountMenu();break;
        default: cout << "Invalid choice, please try again";
        }

    } while (c != '0');
    cout << "Shutting down ..." << endl;
    exit(0);
    
    return 0;
}