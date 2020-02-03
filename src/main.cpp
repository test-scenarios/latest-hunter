#include <iostream>
#include "explain.hpp"
#include "config.hpp"

namespace program {

    using namespace std::literals;

    int
    run()
    {

        return 0;
    }
}

int
main()
{
    try
    {
        return program::run();
    }
    catch (...)
    {
        std::cerr << program::explain() << std::endl;
        return 127;
    }
}