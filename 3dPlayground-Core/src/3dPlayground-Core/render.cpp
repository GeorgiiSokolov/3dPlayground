#include "3dPlayground-Core\render.hpp"
#include "glad\glad.h"
#include <windows.h>

using namespace Playground;

Render::Render() {}

Render::~Render()
{
    DisableOpenGl();
}

int Render::Init(HWND hwnd_arg)
{
    hwnd = hwnd_arg;
    EnableOpenGl();
    gladLoadGL();
    return 0;
}