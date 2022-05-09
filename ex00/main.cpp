#include "Conversion.hpp"

int getType(const std::string value)
{
    size_t i;
    int has_dot = 0;

    if (value.empty())
    {
        std::cout << "Error: empty string" << std::endl;
        return UNKNOWN;
    }
    else if (value == "-inf" || value == "-inff")
		return MINFINITY;
	else if (value == "inf" || value == "inff")
		return INFINITY;
	else if (!isdigit(value.at(0)) && value.size() == 1)
		return CHAR;
    if (value.at(0) == '-' || isdigit(value.at(0)))
	{
		i = 1;
		while (isdigit(value[i]) && i < value.size())
			i++;
		if (i == value.size())
        {
			return INT;
        }
		i = 1;
		while (has_dot <= 1 && i < value.size())
		{
			if (value[i] == '.')
				has_dot++;
			if (!isdigit(value[i]) && value[i] != '.' && (value[i] != 'f' || i != value.size() - 1))
				return NAN;
			i++;
		}
	}
	else
		return NAN;
	if (has_dot > 1)
		return NAN;
	return (value.at(value.size() - 1) == 'f') ? FLOAT : DOUBLE;
}


std::string print_char(int data_type, double data)
{
    std::string str;
    char c;

    // if (data_type == CHAR)
    // {
    //     str = "'";
    //     str += value;
    //     str += "'";
    //     return (str);
    // }
    c = static_cast<char>(data);
    if (data != c || data_type == UNKNOWN || data_type == MINFINITY || data_type == INFINITY || data_type == NAN)
        return ("impossible");
    if (!std::isprint(c))
        return ("Non displayable");
    str = "'";
    str.push_back(c);
    str += "'";
    return (str);
}

std::string print_double(int data_type, std::string value, double data)
{
    std::ostringstream ostr;
    std::string res;

    ostr << data;
    res = ostr.str();
    if (data_type == DOUBLE)
		return (value);
	else if (data_type == NAN)
		return ("nan");
	else if (data_type == INFINITY)
		return ("inf");
	else if (data_type == MINFINITY)
		return ("-inf");
    res += ".0";
    return (res);
}

std::string print_int(int data_type, double data)
{
    int i;
    std::ostringstream ostr;

    if (data < INT_MIN || data > INT_MAX)
        return ("impossible");
    i = static_cast<int>(data);
    if (data != i || data_type == UNKNOWN || data_type == MINFINITY || data_type == INFINITY || data_type == NAN)
        return ("impossible");
    ostr << i;
    return (ostr.str());
}

std::string print_float(int data_type, std::string value, double data)
{
    float f;
    std::string buf = value;
    std::ostringstream ostr;
    std::string res;

    if (data_type == FLOAT)
    {
        buf.push_back('f');
        return (buf);
    }
    if (data < -FLT_MAX || data > FLT_MAX)
        return ("impossible");
    f = static_cast<float>(data);
    if (data_type == NAN)
		return ("nanf");
	else if (data_type == INFINITY)
		return ("inff");
	else if (data_type == MINFINITY)
		return ("-inff");
    ostr << f;
    res = ostr.str();
    res += ".0";
    res += "f";
    return (res);
}

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
    std::cout << "float: " << print_float(data_type, value, data) << std::endl;
    std::cout << "double: " << print_double(data_type, value, data) << std::endl;
    return (0);
}
