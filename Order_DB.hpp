#pragma once
#include "Order.hpp"
#include<vector>
class Order_DB
{

public:
	//DB operations
	static void createOrder(const Order&);
	static Order loadOrderfromDB(string orderID);
	static vector<Order> loadTraderOrdersfromDB(const string& traderid);
	
};

