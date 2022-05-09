#include "Conversion.hpp"

int main(int argc, char **argv)
{
    int data_type = UNKNOWN;
    double data = 0;
    if (argc != 2)
    {
        std::cout << "invalid number of args" << std::endl;
        return (1);
    }
    std::string value(argv[1]);
    data_type = getType(value);
    if (data_type == CHAR)
        data = static_cast<double>(value.at(0));
    else
    {
        if (data_type == FLOAT)
            value.erase(value.find("f"));
        data = (data_type == UNKNOWN) ? 0 : std::strtod(value.c_str(), NULL);
    }
    std::cout << "char: " << print_char(data_type, data) << std::endl;
    std::cout << "int: " << print_int(data_type, data) << std::endl;
    std::cout << "float: " << print_float(data_type, data) << std::endl;
    std::cout << "double: " << print_double(data_type, data) << std::endl;
    return (0);
}
