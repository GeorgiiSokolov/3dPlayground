#include <windows.h>
#include "glad\glad.h"
#include <iostream>
#include <string>
#include <stdio.h>
#include "3dPlayground-Core\application.hpp"
#include "3dPlayground-Core\window.hpp"
#include "3dPlayground-Core\render.hpp"

		const GLchar* vertex_schader_txt = 
			"#version 110\n"
			"varying vec4 color;"
			"void main() { color = gl_Color;"
			"gl_Position = gl_Vertex;"
			"}";

		const GLchar* fragment_schader_txt = 
			"#version 110\n"
			"varying vec4 color;"
			"void main() { gl_FragColor = color;"
			"}";

		GLfloat cubePoints[] =
		{
			0, 0, 0,
			1000, 0, 0,
			1000, 1000, 0,
			0, 1000, 0,

			0, 0, 2000,
			1000, 0, 2000,
			1000, 1000, 2000,
			0, 1000, 2000
		};

		GLfloat cubeColors[] =
		{
			1, 0, 0,
			1, 0, 0,
			1, 0, 0,
			1, 0, 0,
			0, 0, 1,
			0, 0, 1,
			0, 0, 1,
			0, 0, 1
		};

		GLuint cubeIndexes[] =
		{
			0, 1, 2, 3,
			4, 5, 6, 7,
			0, 1, 5, 4,
			2, 3, 7, 6,
			1, 2, 6, 5,
			0, 3, 7, 4
		};
GLuint shader_program, vao;


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

			// Renderer: Intel(R) HD Graphics
			// Vendor: Intel
			// Version: 2.1.0 - Build 8.15.10.2900
			// Shading language version: 1.20  - Intel Build 8.15.10.2900
		
		rnd.Init(hwnd);


		

		printf( "VENDOR = %s", glGetString( GL_VENDOR ) ) ;
		printf( "RENDERER = %s", glGetString( GL_RENDERER ) ) ;
		printf( "VERSION = %s", glGetString( GL_VERSION ) ) ;

		
		
		GLuint vsh = glCreateShader(GL_VERTEX_SHADER);
		glShaderSource(vsh, 1, &vertex_schader_txt, 0);
		glCompileShader(vsh);
		GLint ok;
		GLchar log[2000];
		glGetShaderiv(vsh, GL_COMPILE_STATUS, &ok);
		glGetShaderInfoLog(vsh, 2000, NULL, log);
		printf("\nStatus: %d Log vertex shader:\n%s\n", ok, log);

		GLuint fsh = glCreateShader(GL_FRAGMENT_SHADER);
		glShaderSource(fsh, 1, &fragment_schader_txt, 0);
		glCompileShader(fsh);

		glGetShaderiv(fsh, GL_COMPILE_STATUS, &ok);
		glGetShaderInfoLog(fsh, 2000, NULL, log);
		printf("Status: %d Log fragment shader:\n%s\n", ok, log);

		if(!ok) {return -1;}

		shader_program = glCreateProgram();
		glAttachShader(shader_program, vsh);
		glAttachShader(shader_program, fsh);
		glLinkProgram(shader_program);

		glDeleteShader(fsh);
		glDeleteShader(vsh);
		
		GLuint points_vbo = 0;
		glGenBuffers(1, &points_vbo);
		glBindBuffer(GL_ARRAY_BUFFER, points_vbo);
			glBufferData(GL_ARRAY_BUFFER, sizeof(cubePoints), cubePoints, GL_STATIC_DRAW);
			glVertexPointer(3, GL_FLOAT, 0, nullptr);
		glBindBuffer(GL_ARRAY_BUFFER, 0);

		GLuint color_vbo = 0;
		glGenBuffers(1, &color_vbo);
		glBindBuffer(GL_ARRAY_BUFFER, color_vbo);
			glBufferData(GL_ARRAY_BUFFER, sizeof(cubeColors), cubeColors, GL_STATIC_DRAW);
			glColorPointer(3, GL_FLOAT, 0, nullptr);
		glBindBuffer(GL_ARRAY_BUFFER, 0);

 		/* glEnableVertexAttribArray(0);
		glBindBuffer(GL_ARRAY_BUFFER, points_vbo);
		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, nullptr);

		glEnableVertexAttribArray(1);
		glBindBuffer(GL_ARRAY_BUFFER, color_vbo);
		glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 0, nullptr);
		*/

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

		glClearColor(0.0f, 0.3f, 0.0f, 0.0f);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		glUseProgram(shader_program);
		glEnable(GL_DEPTH_TEST);
		
		glEnableClientState(GL_VERTEX_ARRAY);
		glEnableClientState(GL_COLOR_ARRAY);
			glDrawElements(GL_QUADS, 24, GL_UNSIGNED_INT, &cubeIndexes);
		glDisableClientState(GL_VERTEX_ARRAY);
		glDisableClientState(GL_COLOR_ARRAY);

		

		SwapBuffers(rnd.get_hDC());

		return 0;
	}
}