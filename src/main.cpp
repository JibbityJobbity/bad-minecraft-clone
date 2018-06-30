#include <Universe.hpp>
#include <iostream>

int main()
{
    int universeSetupStatus = 0;
    Universe currentUniverse;
    universeSetupStatus = currentUniverse.Setup();
    if (universeSetupStatus == 0)
        currentUniverse.EventLoop();
    else 
        std::cout << "Universe creation failed with code " << universeSetupStatus << std::endl;
    currentUniverse.Cleanup();
    return 0;
}