#include "Order_IO.hpp"
#include "TRADINGPLATFORM_DEF.hpp"

#include <iostream>
#include <ctime>

ordertype Order_IO::readOrderType()
{
    char ch = '*';
    string prompt = "Do you want to buy or sell (B/S)";
    cout << prompt << endl;
    cin >> ch;
    ch = tolower(ch);

    while (ch != 'b' && ch != 's')
    {
        cout << "Invalid choice" << endl;
        cout << prompt << endl;
        cin >> ch;
        ch = tolower(ch);
    }

    return (ch == 'b')?BUY:SELL;
}

unsigned int Order_IO::readOrderQantity()
{
    unsigned int res = 0;
    string prompt = "Enter the order quantity";
    cout << prompt << endl;
    cin >> res;
    while (res <= 0)
    {
        cout << "Invalid choice" << endl;
        cout << prompt << endl;
        cin >> res;
    }
    return res;
}

double Order_IO::readOrderPrice()
{
    double res = 0.0;
    string prompt = "Enter the order price";
    cout << prompt << endl;
    cin >> res;
    while (res <= 0.0)
    {
        cout << "Invalid choice" << endl;
        cout << prompt << endl;
        cin >> res;
    }
    return res;
}

Order Order_IO::readOrderFromTerminal(string TraderID, string ISINCode)
{

    if (!TraderID.empty() && !ISINCode.empty())
    {
        Order o("", "", "", BUY, 0, 0, 0.0, 0);
        o.setISINCode(ISINCode);
        o.setOrderID(TraderID);
        o.setOrderID(generateUUID());
        o.setOrderType(readOrderType());
        o.setQty(readOrderQantity());
        o.setRemainingQty(o.getQty());
        o.setPrice(readOrderPrice());
        o.setTimeStamp(time(nullptr));//get Current Time
        return o;
    }

}
