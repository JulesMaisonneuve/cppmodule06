#include "Conversion.hpp"

Conversion::Conversion(void)
{
    return ;
}

Conversion::Conversion(const Conversion &c)
{
    return ;
}

// Conversion& Conversion::operator=(const Conversion &other)
// {
//     return ;
// }

void Conversion::checkType(const std::string data)
{

}

bool isNumber(const std::string &data)
{
    for (; *data; ++data)
    {
        if(!std::isdigit(*data))
            return false;
    }
    return true;
}


Conversion::~Conversion(void)
{
    return ;
}