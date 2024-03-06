#include <iostream>
#include <memory>
class Base {
public:
private:
        int _data{0};
};

int main()
{
    std::shared_ptr<Base> ptr = std::make_shared<Base>();
    ptr.reset();

    return 0;
}

