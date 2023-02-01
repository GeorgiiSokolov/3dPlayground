#pragma once
#include <iostream>
#include "3dPlayground-Core\application.hpp"

namespace Player
{
    class PlayerApp : public Playground::Application
    {
        virtual int OnRedraw() override;
    };
}