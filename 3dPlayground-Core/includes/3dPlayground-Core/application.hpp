#pragma once
#include <windows.h>
#include <string>
#include "3dPlayground-Core\window.hpp"

namespace Playground
{
    class Window;
    class Application
    {
        public:
            Application(HINSTANCE hInstance, int nCmdShow,
                            unsigned int width, unsigned int height,
                            std::string name);
            virtual ~Application();

            virtual int Start();

            virtual int OnUpdate();

            Window wnd;
    };
}
