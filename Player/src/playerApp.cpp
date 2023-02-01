#include "playerApp.hpp"
#include <iostream>

using namespace Player;

int PlayerApp::OnRedraw()
{
    std::cout << "OnRedraw invoked." << std::endl;
    return 0;
}