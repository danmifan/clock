#include <clock.h>
#include <thread>

void test() {
	std::this_thread::sleep_for(std::chrono::seconds(1));
}

int main(int argc, char const *argv[])
{
	CLOCK(test(), std::chrono::milliseconds);

	Clock c;
	test();
	c.stop();
	std::cout << c.getDurationAs<std::chrono::milliseconds>() << std::endl;
	return 0;
}