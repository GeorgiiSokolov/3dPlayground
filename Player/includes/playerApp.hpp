#pragma once
#include <iostream>
#include "3dPlayground-Core\application.hpp"

namespace Player
{
    class PlayerApp : public Playground::Application
    {
        public:
            PlayerApp(HINSTANCE hInstance, int nCmdShow,
                            unsigned int width, unsigned int height,
                            std::string name) 
                : Application(hInstance, nCmdShow, width, height, name) {}
        private:    
            virtual int OnUpdate() override;
    };
}