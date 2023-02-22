#include "playerApp.hpp"
#include <iostream>
#include "glad\glad.h"
#include "glm\glm.hpp"
#include "glm\gtx\transform.hpp"
#include "glm\gtc\type_ptr.hpp"

GLuint cubeIndexes[] =
{
	0, 1, 2, 3,
	4, 5, 6, 7,
	0, 1, 5, 4,
	2, 3, 7, 6,
	1, 2, 6, 5,
	0, 3, 7, 4
};

using namespace Player;

int PlayerApp::OnUpdate()
{
    glClearColor(0.0f, 0.3f, 0.0f, 0.0f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    
    glUseProgram(wnd.rnd.shader_program);

    glm::mat4 matModel(0.2f, 0.0f, 0.0f, 0.0f,
                        0.0f, 0.2f, 0.0f, 0.0f,
                        0.0f, 0.0f, 0.2f, 0.0f,
                        0.0f, 0.0f, 0.0f, 1.0f);
    glm::mat4 matView(1.0f);
    matView = glm::translate(matView, glm::vec3(0.5f, 0.0f, 0.0f));
    glm::mat4 matProjection(1.0f);
    //matProjection = glm::perspective(45.0f, 1.0f, 0.01f, 10.0f);
    glm::mat4 mvp = matProjection * matView * matModel;
    
    glUniformMatrix4fv(wnd.rnd.mvp_Id, 1, GL_FALSE, glm::value_ptr(mvp));
    glEnable(GL_DEPTH_TEST);
    
    glEnableClientState(GL_VERTEX_ARRAY);
    glEnableClientState(GL_COLOR_ARRAY);
		glDrawElements(GL_QUADS, 24, GL_UNSIGNED_INT, &cubeIndexes);
	glDisableClientState(GL_VERTEX_ARRAY);
	glDisableClientState(GL_COLOR_ARRAY);
    return 0;
}