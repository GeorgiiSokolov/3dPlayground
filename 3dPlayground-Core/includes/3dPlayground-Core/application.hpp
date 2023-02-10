#pragma once
#include <windows.h>
#include <string>

namespace Playground
{
    class Application
    {
        public:
            Application();
            virtual ~Application();

            virtual int Start(HINSTANCE hInstance, int nCmdShow,
                                unsigned int width, unsigned int height,
                                std::string name);

            virtual int OnUpdate();
    };
}
