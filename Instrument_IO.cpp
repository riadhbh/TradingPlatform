#include "Instrument_IO.hpp"
#include <iostream>
#include <string>
#include <regex>

bool isValidISIN(const std::string& isin) {
    // ISIN code should be 12 characters long
    if (isin.length() != 12) {
        return false;
    }

    // ISIN code should contain only uppercase letters and digits
    for (char c : isin) {
        if (!std::isalnum(c) || std::islower(c)) {
            return false;
        }
    }

    return true;
}


std::string Instrument_IO::readISINCode() {
    std::string isinCode;
    while (true) {
        std::cout << "Enter the ISIN code: ";
        std::cin >> isinCode;

        if (isValidISIN(isinCode)) {
            break; // Exit the loop if the entered ISIN is valid
        }
        else {
            std::cout << "Invalid ISIN code. Please enter a valid 12-character code consisting of uppercase letters and digits." << std::endl;
        }
    }
    return isinCode;
}

Instrument Instrument_IO::readInstrumentFromTerminal()
{
	//return Instrument();
}
