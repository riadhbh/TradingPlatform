#include "TRADINGPLATFORM_DEF.hpp"

std::string generateUUID()
{
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(0, 15);

    const char* hexChars = "0123456789abcdef";
    std::stringstream ss;

    for (int i = 0; i < 32; ++i) {
        ss << hexChars[dis(gen)];
        if (i == 7 || i == 11 || i == 15 || i == 19)
            ss << '-';
    }

    return ss.str();
}