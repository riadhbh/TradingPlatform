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
            case '1': tmp_Trader.setEmail(Trader_IO::readEmail(true));
                      cout<<"Do you Want to update another thing? (Y/N)"<<endl;
                      cin >> c;
                      break;
            case '2': tmp_Trader.setPhoneNumber(Trader_IO::readPhoneNumber()); 
                      cout << "Do you Want to update another thing? (Y/N)" << endl; 
                      cin >> c;
                      break;
            case '3': cPassword = Trader_IO::readSinglePassword("Enter the current password : ");   
                        if (cPassword != tmp_Trader.getPassword())
                        {
                            cout << "Password incorrect please try again !" << endl;
                        }
                        else
                        {
                            tmp_Trader.setPassword(Trader_IO::readPasswords());
                            cout << "Do you Want to update another thing? (Y/N)" << endl;
                            cin >> c;
                        }
                        break;
            default: cout << "Invalid choice, please try again" << endl; break;
            }
            
        } while (c != '0' && tolower(c) != 'n');

        // Collect all the updates and send them to the DB in one single request

        if (tmp_Trader != currentTrader)
        {
            Trader_DB::updateTraderAccount(tmp_Trader);
            currentTrader = tmp_Trader;
            cout << currentTrader;
        }
    }
    catch(exception & e)
    { 
        cerr << e.what() << endl;
    }
}

bool TradingPlatform::DeleteTraderMenu()
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
                    return false;
                }
                else
                {
                    Trader_DB::deleteTraderAccount(currentTrader.getTraderID());
                    currentTrader = Trader("", "", "", "", "", "", "", false, false);
                    return true;
                }
                
            }

        } while (c != '0' && tolower(c)!='y' && tolower(c) != 'n');
    }
    catch (exception& e)
    {
        cerr << e.what() << endl;
        return false;
    }

}

void TradingPlatform::ManageInstrumentsMenu()
{
    cout << "*** Instruments manager ***" << endl;
    char c = '*';
    do
    {
        cout << "0) Back to previous menu" << endl;
        cout << "1) View Instruments" << endl;
        cout << "2) Add a new Instrument" << endl;
        cout << "3) Update an instrument" << endl;
        cout << "3) Disable an instrument" << endl;
        cin >> c;

        switch (c)
        {
        case '0': break;
        case '1': cout << "*** List of instruments ***" << endl;
            cout << "Tradable instruments" << endl;
            cout << "Disabled instruments" << endl;
            break;
        case '2': 
            cout << "Create a new instrument" << endl;
            break;
        case '3': cout << "Please enter the instrument ISIN code " << endl;
            break;
        default: cout << "Invalid choice, please try again" << endl; break;
        }

    } while (c != '0' && tolower(c) != 'n');

}

void TradingPlatform::TraderMenu()
{
    cout << endl <<"*** Welcome " << currentTrader.getFirstName() << " ! ***" << endl;
    char c = '*';
    do
    {
        cout << "0) Logout" << endl;
        cout << "1) View account information" << endl;
        cout << "2) View orderbook" << endl;
        cout << "3) Delete account" << endl;
        if(currentTrader.isAdmin())
            cout << "4) Manage instruments" << endl;
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
        case '3': if(DeleteTraderMenu())
                        c = '0';//logout
                  break;
        case '4': if (currentTrader.isAdmin())
                  {
                    ManageInstrumentsMenu();
                  }break;
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