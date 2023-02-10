#include <windows.h>
#include "glad\glad.h"
#include <iostream>
#include <string>
#include "3dPlayground-Core\application.hpp"
#include "3dPlayground-Core\window.hpp"

namespace Playground
{
    Application::Application()
    {

    }

    Application::~Application()
    {

    }

    int Application::Start(HINSTANCE hInstance, int nCmdShow,
                            unsigned int width, unsigned int height,
                            std::string name)
    {
        Window wnd = Window(hInstance, nCmdShow, width, height, name);
        while(!wnd.get_bQuit())
        {
            wnd.OnUpdate();
            OnUpdate();
        }
        return 0;
    }

    int Application::OnUpdate()
    {
        return 0;
    }
}