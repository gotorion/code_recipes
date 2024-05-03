#include <optional>
#include <iostream>
#include <thread>
int main()
{
    auto closure = [](bool create) -> std::optional<int>
    {
        if (create)
        {
            return std::make_optional(999);
        }
        else
        {
            return std::nullopt;
        }
    };
    auto result = closure(true);
    std::cout << result.value_or(-1) << std::endl;
    return 0;
}