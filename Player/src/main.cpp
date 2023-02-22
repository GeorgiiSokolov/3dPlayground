#include <windows.h>
#include "3dPlayground-Core\application.hpp"
#include "playerApp.hpp"

using namespace Player;


int WINAPI WinMain(HINSTANCE hInstance,
                   HINSTANCE hPrevInstance,
                   LPSTR lpCmdLine,
                   int nCmdShow)
{
    PlayerApp app(hInstance, nCmdShow, 800, 600, std::string("Player"));
    app.Start();
    return 0;
}
