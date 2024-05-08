#include <tuple>
#include <iostream>

void test_tuple_get()
{
    auto tup = std::tuple(2, 3.12, "Hello World"); // no need to explicit write type
    std::cout << std::get<0>(tup) << std::endl;
    std::cout << std::get<1>(tup) << std::endl;
    std::cout << std::get<2>(tup) << std::endl;
}

void test_struct_bind()
{
    auto tup = std::tuple(2, 3.12, "Hello World"); // no need to explicit write type
    // auto [first, second, third] = tup;
    // std::cout << first << " " << second << " " << third << std::endl;
    auto &[first, second, third] = tup; // bind as reference
    std::cout << first << std::endl;
    first = 10;
    std::cout << first << std::endl;

    struct Complex
    {
        int x{10};
        int y{20};
    };
    auto [real, virt] = Complex(); // even for struct
                                   // sadly std::get can not be used for struct
    std::cout << real << "." << virt << std::endl;
}
int main()
{
    test_struct_bind();
}