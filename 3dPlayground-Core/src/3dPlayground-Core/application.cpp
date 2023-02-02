#include <windows.h>
#include "glad\glad.h"
#include <iostream>
#include <string>
#include "3dPlayground-Core\application.hpp"
#include "3dPlayground-Core\enable-disableOpenGL.hpp"

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
        WNDCLASSEX wcex;
        HWND hwnd;
        HDC hDC;
        HGLRC hRC;
        MSG msg;
        BOOL bQuit = FALSE;
        float theta = 0.0f;
        float d = 0;

        /* register window class */
        wcex.cbSize = sizeof(WNDCLASSEX);
        wcex.style = CS_OWNDC;
        wcex.lpfnWndProc = WindowProc;
        wcex.cbClsExtra = 0;
        wcex.cbWndExtra = 0;
        wcex.hInstance = hInstance;
        wcex.hIcon = LoadIcon(NULL, IDI_APPLICATION);
        wcex.hCursor = LoadCursor(NULL, IDC_ARROW);
        wcex.hbrBackground = (HBRUSH)GetStockObject(BLACK_BRUSH);
        wcex.lpszMenuName = NULL;
        wcex.lpszClassName = "GLSample";
        wcex.hIconSm = LoadIcon(NULL, IDI_APPLICATION);


        if (!RegisterClassEx(&wcex))
            return 0;

        /* create main window */
        hwnd = CreateWindowEx(0,
                            "GLSample",
                            name.c_str(),
                            WS_OVERLAPPEDWINDOW,
                            CW_USEDEFAULT,
                            CW_USEDEFAULT,
                            500,
                            500,
                            NULL,
                            NULL,
                            hInstance,
                            NULL);

        ShowWindow(hwnd, nCmdShow);

            // Renderer: Intel(R) HD Graphics
            // Vendor: Intel
            // Version: 2.1.0 - Build 8.15.10.2900
            // Shading language version: 1.20  - Intel Build 8.15.10.2900
        
        EnableOpenGL(hwnd, &hDC, &hRC);

        if (!gladLoadGL())
        {
            std::cout << "Failed to load GL! " << std::endl;
            return -1;
        }

        std::cout << "GL ver: " << GLVersion.major << " " << GLVersion.minor << std::endl;

        	while (!bQuit)
            {
                /* check for messages */
                //PeekMessage returns immediately.
                //GetMessage only when the message arrives.

                if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))
                {
                    /* handle or dispatch messages */
                    if (msg.message == WM_QUIT)
                    {
                        bQuit = TRUE;
                    }
                    else
                    {
                        TranslateMessage(&msg);
                        DispatchMessage(&msg);
                    }

                }
                else
                {
                    /* OpenGL animation code goes here */

                    OnRedraw();
                }
            }

        /* shutdown OpenGL */
        DisableOpenGL(hwnd, hDC, hRC);

        /* destroy the window explicitly */
        DestroyWindow(hwnd);

        return msg.wParam;
    }

    LRESULT CALLBACK Application::WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
    {
        switch (uMsg)
        {
            case WM_CLOSE:
                PostQuitMessage(0);
            break;

            case WM_DESTROY:
                return 0;

            case WM_KEYDOWN:
            {
                switch (wParam)
                {
                    case VK_ESCAPE:
                        PostQuitMessage(0);
                    break;
                }
            }
            break;

            default:
                return DefWindowProc(hwnd, uMsg, wParam, lParam);
        }

        return 0;
    }

    int Application::OnRedraw()
    {
        return 0;
    }
}