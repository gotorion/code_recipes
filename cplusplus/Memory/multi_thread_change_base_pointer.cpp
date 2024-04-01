#include <iostream>
#include <memory>
#include <thread>
#include <functional>
class IWafer {
    public:
        virtual void SetNewValue(int val) = 0;
};

class Wafer : public IWafer {
    public:
        void SetNewValue(int val) override {
            val_ = val;
        }
        void PrintVal() {
            std::cout << "val = " << val_ << std::endl;
        }
    private:
        int val_{0};
};
static std::shared_ptr<Wafer> g_wafer;
std::shared_ptr<IWafer> factoryFunc() {
    g_wafer = std::make_shared<Wafer>();
    return g_wafer; 
}

void threadFunc(std::shared_ptr<IWafer> wafer) {
    wafer->SetNewValue(10);
}

int main() {
    std::shared_ptr<IWafer> tempWafer = factoryFunc();
    g_wafer->PrintVal();
    std::this_thread::sleep_for(std::chrono::seconds(3));
    std::thread th(threadFunc, tempWafer);
    std::this_thread::sleep_for(std::chrono::seconds(3));
    g_wafer->PrintVal();
    th.join();
    return 0;
}