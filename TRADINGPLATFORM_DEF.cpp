#include "TRADINGPLATFORM_DEF.hpp"

std::string generateUUID()
{
    UUID uuid;
    UuidCreate(&uuid);

    unsigned char* str;
    UuidToStringA(&uuid, &str);

    std::string uuidStr(reinterpret_cast<char*>(str));
    RpcStringFreeA(&str);

    return uuidStr;
}