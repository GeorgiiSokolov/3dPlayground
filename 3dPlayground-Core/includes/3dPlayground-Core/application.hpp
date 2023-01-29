#pragma once
#include <string>

namespace Playground
{
    class Application
    {
        public:
            Application();
            virtual ~Application();

            virtual int Start(unsigned int width, unsigned int height, std::string name);
            virtual int OnRedraw();
    };
}
