#include <stdio.h>

#define max(x, y) ({\
    typeof(x) _max1 = (x);\
    typeof(y) _max2 = (y);\
    (void) (&_max1 == &_max2);\
    _max1 > _max2 ? _max1 : _max2;\
})

int main() {
    int x = 1;
    double y = 2;
    printf("%d\n", max(x, y));
}