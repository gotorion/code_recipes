#include <variant>
#include <iostream>
#include <string>

class Num
{
public:
    Num(int num)
        : data_(num)
    {
    }
    int get() { return data_; }

private:
    int data_;
};

int main()
{
    std::variant<int, double, std::string, Num> value;

    value = 10;
    std::cout << std::get<int>(value) << std::endl;

    value = "Hello world";
    std::cout << std::get<std::string>(value) << std::endl;
    // use index() to find which value was set
    std::cout << "Current value index: " << value.index() << std::endl;

    value = true; // this is ok
    std::cout << std::get<int>(value) << std::endl;

    value = Num(10); // unlike union, class type and non-POD type is allowed
    std::cout << std::get<Num>(value).get() << std::endl;

    // monostate
    //    std::variant<Num, int> another_value; // no default construct for Num class, this is an error
    std::variant<std::monostate, Num, int> another_value; // ok
    if (!another_value.index())
    {
        std::cout << "Monostate" << std::endl;
    }
    if (std::holds_alternative<std::monostate>(another_value))
    {
        std::cout << "Monostate" << std::endl;
    }
    if (std::get_if<0>(&another_value))
    {
        std::cout << "Monostate" << std::endl;
    }
    another_value = 888;
    if (std::holds_alternative<std::monostate>(another_value))
    {
        std::cout << "Monostate" << std::endl;
    }
    else
    {
        std::cout << "No monostate" << std::endl;
    }

    return 0;
}
