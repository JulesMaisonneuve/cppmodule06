#include "Data.hpp"

int main(void)
{
	Data* data = new Data();
	std::cout << data << std::endl;
	std::cout << deserialize(serialize(data)) << std::endl;
	return 0;
}
