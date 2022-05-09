#ifndef DATA_HPP
# define DATA_HPP

# include <stdint.h>
# include <iostream>

class Data
{
	private:
	public:
		Data(void);
		Data(const Data &d);
		Data &operator=(const Data &other);
		~Data(void);
};

uintptr_t serialize(Data *ptr);
Data *deserialize(uintptr_t raw);

#endif
