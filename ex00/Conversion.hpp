#ifndef CONVERSION_HPP
# define CONVERSION_HPP

# include <iostream>
# include <cctype>

enum dataType
{
    INT,
    CHAR,
    FLOAT,
    DOUBLE,
    UNKNOWN
};

class Conversion
{
    private:
    public:
        Conversion(void);
        Conversion(const Conversion &other);
        Conversion &operator=(const Conversion &other);
        void checkType(const std::string data);
        ~Conversion(void);

};

#endif