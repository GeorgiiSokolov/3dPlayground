#include <windows.h>
#include <iostream>
#include <string>
#include "3dPlayground-Core\application.hpp"
#include "3dPlayground-Core\render.hpp"
#include "3dPlayground-Core\window.hpp"


namespace Playground
{
    Application::Application(HINSTANCE hInstance, int nCmdShow,
                            unsigned int width, unsigned int height,
                            std::string name)
    : wnd(Window(hInstance, nCmdShow, width, height, name))
    {

    }

    Application::~Application()
    {

    }

    int Application::Start()
    {
        while(!wnd.get_bQuit())
        {
            wnd.OnUpdate();
            OnUpdate();
            wnd.rnd.Swap();
        }
        return 0;
    }

    int Application::OnUpdate()
    {
        return 0;
    }
}