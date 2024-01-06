#include "util.hpp"

#include <iostream>

auto main() -> int
{
    std::string str = "hola que hace";
    const auto vec = cst::str_split(str);
    std::cout << vec[0] << '\n';
    return 0;
}
