#pragma once
#include "referenceCounter.h"

class ProcessData : public ReferenceCounter {
    public:
        ProcessData(int id, std::string info) : _id(id), _info(info) {
            std::cout << "ProcessData Constructor" << std::endl;
        }
        ProcessData(const ProcessData& other) : _id(other._id), _info(other._info) {
            std::cout << "ProcessData Copy constructor" << std::endl;
        }
        ProcessData& operator=(const ProcessData& other) {
            _id = other._id;
            _info = other._info;
            std::cout << "PricessData Assignment Operator" << std::endl;
            return *this;
        }
        ~ProcessData() {
            std::cout << "ProcessData Destructor" << std::endl;
        }
    private:
        int _id;
        std::string _info;
};