#ifndef CONVERSION_HPP
# define CONVERSION_HPP

# include <iostream>
# include <cctype>
# include <cstdlib>
# include <sstream>
# include <limits.h>
# include <float.h>

enum dataType
{
    INT,
    CHAR,
    FLOAT,
    DOUBLE,
    UNKNOWN,
    MINFINITY,
    INFINITY,
    NAN
};

int getType(const std::string value);
bool has_only_digits(std::string str);
bool is_int(std::string str);
std::string print_char(int data_type, double data);
std::string print_double(int data_type, double data);
std::string print_int(int data_type, double data);
std::string print_float(int data_type, double data);

#endif
