#pragma once

#include "Instrument.hpp"
using namespace std;

class Instrument_IO
{
public :
	string readISINCode();
	static Instrument readInstrumentFromTerminal();
};