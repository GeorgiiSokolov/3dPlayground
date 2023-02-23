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
            int Swap();

            GLuint points_vbo;
            GLuint indexes_ebo;
            GLuint color_vbo;
            GLuint shader_program, vao;
            GLint mvp_Id;

            

        private:
            void EnableOpenGl();
            void DisableOpenGl();

            HDC hDC;
            HWND hwnd;
            HGLRC hRC;
    };
}