#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

int main(void)
{
    Base *base;
    base = generate();
    identify(*base);
    identify(base);
    delete base;
    return 0;
}
