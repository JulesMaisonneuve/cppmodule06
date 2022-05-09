#include "Data.hpp"

Data::Data(void)
{
	return ;
}

Data& Data::operator=(const Data &other)
{
	if (this == &other)
		return *this;
	return *this;
}

Data::Data(const Data &other)
{
	*this = other;
	return ;
}

Data::~Data(void)
{
	return ;
}

uintptr_t serialize(Data *ptr)
{
	return (reinterpret_cast<uintptr_t>(ptr));
}

Data *deserialize(uintptr_t raw)
{
	return (reinterpret_cast<Data*>(raw));
}
