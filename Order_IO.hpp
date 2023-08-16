#pragma once
#include "Order.hpp"
class Order_IO
{

public:
	static ordertype readOrderType();
	static unsigned int readOrderQantity();
	static double readOrderPrice();
	static Order readOrderFromTerminal(string TraderID, string ISINCode);
};

