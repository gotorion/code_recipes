#include <variant>
#include <iostream>
#include <iomanip>
int main()
{
    std::variant<int, float, std::string> var;
    var = 10;
    std::visit([](auto &&arg)
               { std::cout << arg << '\n'; }, var);

    var = std::string("Hello world");
    // try std::quoted(io manipulate)
    std::cout << std::quoted(std::get<std::string>(var), '|') << std::endl;
    return 0;
}