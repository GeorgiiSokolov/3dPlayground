#include <windows.h>
#include "glad\glad.h"
#include "3dPlayground-Core\render.hpp"
#include "3dPlayground-Core\window.hpp"


using namespace Playground;

Render::Render()
{

}

Render::~Render()
{
    DisableOpenGl();
}

int Render::Init(HWND a_hwnd)
{
    hwnd = a_hwnd;
    EnableOpenGl();
    gladLoadGL();

    const GLchar* vertex_schader_txt = 
    "#version 110\n"
    "uniform mat4 mvp;"
    "varying vec4 color;"
    "void main() { color = gl_Color;"
    "gl_Position = mvp * vec4(gl_Vertex.xyz, 1.0);"
    "}";

    const GLchar* fragment_schader_txt = 
    "#version 110\n"
    "varying vec4 color;"
    "void main() { gl_FragColor = color;"
    "}";

            // Renderer: Intel(R) HD Graphics
        // Vendor: Intel
        // Version: 2.1.0 - Build 8.15.10.2900
        // Shading language version: 1.20  - Intel Build 8.15.10.2900
    
    

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

    GLfloat cubePoints[] =
    {
        0, 0, 0,
        1, 0, 0,
        1, 1, 0,
        0, 1, 0,

        0, 0, 2,
        1, 0, 2,
        1, 1, 2,
        0, 1, 2
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

    points_vbo = 0;
    glGenBuffers(1, &points_vbo);
    glBindBuffer(GL_ARRAY_BUFFER, points_vbo);
        glBufferData(GL_ARRAY_BUFFER, sizeof(cubePoints), cubePoints, GL_STATIC_DRAW);
        glVertexPointer(3, GL_FLOAT, 0, nullptr);
    glBindBuffer(GL_ARRAY_BUFFER, 0);

    color_vbo = 0;
    glGenBuffers(1, &color_vbo);
    glBindBuffer(GL_ARRAY_BUFFER, color_vbo);
        glBufferData(GL_ARRAY_BUFFER, sizeof(cubeColors), cubeColors, GL_STATIC_DRAW);
        glColorPointer(3, GL_FLOAT, 0, nullptr);
    glBindBuffer(GL_ARRAY_BUFFER, 0);

    mvp_Id = glGetUniformLocation(shader_program, "mvp");

    return 0;
}

int Render::Swap()
{
    SwapBuffers(hDC);
    return 0;
}