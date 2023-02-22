#pragma once
#include <windows.h>
#include <string>
#include "3dPlayground-Core\render.hpp"

namespace Playground
{
    class Window
    {
        public:
            Window(HINSTANCE hInstance, int nCmdShow,
                            unsigned int width, unsigned int height,
                            std::string name);
            virtual ~Window();

            virtual int OnUpdate();

            unsigned int get_height() { return height; }
            unsigned int get_width() { return width; }
            int get_bQuit() { return bQuit; }
            HWND get_hwnd() { return hwnd; }
        
            Render rnd;

        private:

            int Init();
            
            static LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

            HINSTANCE hInstance;
            int nCmdShow;
            unsigned int width;
            unsigned int height;
            std::string name;
            HWND hwnd;
            MSG msg;
            int bQuit;
            
    };
}
