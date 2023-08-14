#include "Order_IO.hpp"

Order Order_IO::readOrderFromTerminal()
{
    Order o("", "", "", BUY, 0, 0, 0, 0);
    return o;
}
