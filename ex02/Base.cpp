#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base::~Base(void)
{
    return ;
}

Base * generate(void)
{
    Base *base;
    srand (time(NULL));
    int res = (rand() % 3);
    switch (res)
    {
    case 0:
        std::cout << "Creating A class" << std::endl;
        base = new A();
        break ;
    case 1:
        std::cout << "Creating B class" << std::endl;
        base = new B();
        break ;
    case 2:
        std::cout << "Creating C class" << std::endl;
        base = new C();
        break ;
    default:
        return (NULL);
    }
    return (base);
}

void identify(Base *p)
{
    if (dynamic_cast<A*>(p))
        std::cout << "Class A" << std::endl;
    else if (dynamic_cast<B*>(p))
        std::cout << "Class B" << std::endl;
    else if (dynamic_cast<C*>(p))
        std::cout << "Class C" << std::endl;
    else 
        std::cout << "Unknown type" << std::endl;
}

void identify(Base& p)
{
    try
    {
        (void)dynamic_cast<A&>(p);
         std::cout << "Class A" << std::endl;
    }
    catch(const std::exception& e)
    {
    }
    try
    {
        (void)dynamic_cast<B&>(p);
         std::cout << "Class B" << std::endl;
    }
    catch(const std::exception& e)
    {
    }
    try
    {
        (void)dynamic_cast<C&>(p);
         std::cout << "Class C" << std::endl;
    }
    catch(const std::exception& e)
    {
    }
}
