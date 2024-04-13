#include <iostream>
#include <future>
#include <thread>
#include <functional>
#include <exception>
int cal_square(std::future<int> &fu)
{
	int x;
	try
	{
		x = fu.get();
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << '\n';
	}

	std::cout << "x * x = " << x * x << std::endl;
	return x * x;
}

int main()
{
	std::promise<int> prom;
	std::future<int> fu = prom.get_future();
	std::future resFuture = std::async(std::launch::async, cal_square, std::ref(fu));

	std::this_thread::sleep_for(std::chrono::seconds(3));
	// exception
	prom.set_exception(std::make_exception_ptr(std::runtime_error("Human create error")));
	// normal
	// prom.set_value(9);
	// int res = resFuture.get();
	// std::cout << "res get from child thread = " << res << std::endl;
	return 0;
}
