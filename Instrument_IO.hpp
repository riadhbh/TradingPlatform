#pragma once

#include "Instrument.hpp"
using namespace std;

class Instrument_IO
{
public :
	static string readISINCode();
	static string readInstrumentName();
	static double readStrikePrice();
	static int    readQuantity();
	static bool   readIsActive();

	static Instrument readInstrumentFromTerminal();
};