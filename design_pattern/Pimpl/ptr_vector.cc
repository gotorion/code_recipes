#include <iostream>
#include <vector>
#include "ptr_vector.hpp"

struct ptr_vector_base::impl {
    std::vector<void*> vp;
    void push_back(void* p) {
        vp.push_back(p);
    }

    void print() const {
        for (void const * const p : vp) {
            std::cout << p << "\n";
        }
    }
};
