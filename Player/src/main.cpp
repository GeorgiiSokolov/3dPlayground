#include <windows.h>
#include "3dPlayground-Core\application.hpp"
#include "playerApp.hpp"

using namespace Player;


int WINAPI WinMain(HINSTANCE hInstance,
                   HINSTANCE hPrevInstance,
                   LPSTR lpCmdLine,
                   int nCmdShow)
{
    PlayerApp app;
    app.Start(hInstance, nCmdShow, 320, 240, std::string("Player"));
    return 0;
}
