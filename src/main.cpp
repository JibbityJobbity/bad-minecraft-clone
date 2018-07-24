#include <Universe.hpp>
#include <iostream>

int main()
{
	int universeSetupStatus = 0;

	Universe currentUniverse = Universe(&universeSetupStatus);

	if (universeSetupStatus == 0)
		currentUniverse.EventLoop();
	else
		std::cout << "Universe creation failed with code " << universeSetupStatus << std::endl;
	return 0;
}
