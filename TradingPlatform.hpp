/**
 * Trading platform.hpp
 * Contains menus
 * 24-07-2023:MRBH:creation
 */
#pragma once

#include "Instrument.hpp"
#include "Order.hpp"
#include "Trader.hpp"

#include <iostream>
#include "Trader_IO.hpp"
#include "Trader_DB.hpp"
#include "Instrument_IO.hpp"
#include "Instrument_DB.hpp"
#include "Order_IO.hpp"
#include "Order_DB.hpp"

class TradingPlatform
{
public :
	static void LoginMenu();
	static void CreateTraderAccountMenu();
	static void TraderMenu();
	static void UpdateTraderMenu();
	static void UpdateInstrumentMenu(Instrument& inst);
	static bool DeleteTraderMenu();
	static void ManageInstrumentsMenu();
};