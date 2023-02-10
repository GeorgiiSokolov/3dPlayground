#pragma once

#include "glad\glad.h"
#include <windows.h>

namespace Playground
{
    class Render
    {
        public:
            Render();
            ~Render();
            int Init(HWND hwnd);
            HDC get_hDC() { return hDC; }

        private:
            void EnableOpenGl();
            void DisableOpenGl();

            HWND hwnd;
            HDC hDC;
            HGLRC hRC;
    };
}