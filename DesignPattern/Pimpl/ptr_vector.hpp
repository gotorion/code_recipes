#pragma once
#include <memory>

class ptr_vector_base
{
public:
    ptr_vector_base() : pImpl(nullptr) {}
    ~ptr_vector_base() {}
protected:
    void push_back_fwd(void*);
    void print() const;
private:
    struct impl;
    std::unique_ptr<impl> pImpl;
};

template<typename T>
class ptr_vector : private ptr_vector_base {
public:
    void push_back(T* p) {
        push_back_fwd(p);
    }
    void print() const {
        ptr_vector_base::print();
    }
};
