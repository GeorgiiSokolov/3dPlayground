#include <windows.h>
#include "glad\glad.h"
#include <iostream>
#include <string>
#include <stdio.h>
#include "glm\glm.hpp"
#include "glm\gtc\type_ptr.hpp"
#include "glm\gtx\string_cast.hpp"
#include "3dPlayground-Core\application.hpp"
#include "3dPlayground-Core\window.hpp"
#include "3dPlayground-Core\render.hpp"

namespace Playground
{
	Window::Window(HINSTANCE hInstance, int nCmdShow,
							unsigned int width, unsigned int height,
							std::string name)
	: hInstance(hInstance)
	, nCmdShow(nCmdShow)
	, width(width)
	, height(height)
	, name(std::move(name))
	, bQuit(FALSE)
	{
		std::cout << "Window constructer started." << std::endl;
		int returnCode = Init();
	}

	Window::~Window()
	{
		/* destroy the window explicitly */
		DestroyWindow(hwnd);

		std::cout << "Window is destructed." << std::endl;
	}

	int Window::Init()
	{
		WNDCLASSEX wcex;
		
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
							width,
							height,
							NULL,
							NULL,
							hInstance,
							NULL);

		ShowWindow(hwnd, nCmdShow);
		rnd.Init(hwnd);
		return 0;
	}

	LRESULT CALLBACK Window::WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
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

	int Window::OnUpdate()
	{
		while (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))
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
		
		return 0;
	}
}