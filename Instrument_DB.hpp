#pragma once
#include "Instrument.hpp"
#include <vector>

using namespace std;

class Instrument_DB
{
public:
	//DB CRUD
	static void createInstrument(const Instrument&);
	static Instrument LoadInstrumentfromDB(string ISINCode);
	static vector<Instrument> loadAllInstruments();
	static void updateInstrument(const Instrument&);
	static void deleteInstrument(const string&);
	static bool ISINCodeExistsinDB(const std::string& ISINCode);
};