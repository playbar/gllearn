#include "linmath.h"

#include <stdlib.h>
#include <stdio.h>
#include "ModelObject.h"


ModelObject *gModelObject =NULL;
bool bleftpress = false;
bool brightpress = false;

GLint gWidth = 640;
GLint gHeith = 480;

GLfloat glastx = 0;
GLfloat glasty = 0;

static void error_callback(int error, const char* description)
{
    fprintf(stderr, "Error: %s\n", description);
}

static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
        glfwSetWindowShouldClose(window, GLFW_TRUE);
}

void mouse_button_callback( GLFWwindow* window, int button, int action, int mods )
{

    printf("button = %d, action=%d, mods = %d\n", button, action, mods );

    if( GLFW_MOUSE_BUTTON_LEFT == button )
    {
        if( GLFW_PRESS == action )
        {
            bleftpress = true;
        }
        else if(GLFW_RELEASE == action )
        {
            bleftpress = false;
        }
    }
    if( GLFW_MOUSE_BUTTON_RIGHT == button )
    {
        if( GLFW_PRESS == action )
        {
            brightpress = true;
        }
        else if(GLFW_RELEASE == action )
        {
            brightpress = false;
        }
    }
}

void cursor_position_callback(GLFWwindow* window, double x, double y)
{

    float dx = x - glastx;
    float dy = y - glasty;

    glastx = x;
    glasty = y;


    if( bleftpress ) {
        float posx = dx * 2 / gModelObject->GetScreenWidth();
        float posy = -dy * 2 / gModelObject->GetScreenHeight();

        printf("dx =%f, dy = %f \n", posx, posy);
        gModelObject->MoveAction(posx, posy);
    }
    if( brightpress )
    {
        float dX = -(float) dx / gModelObject->GetScreenWidth();
        float dY = (float) dy / gModelObject->GetScreenHeight();
        float posX = 2* x / gModelObject->GetScreenWidth() - 1.0;
        float posY = -2* y / gModelObject->GetScreenHeight() + 1.0;
        posX = fmax(-1., fmin(1., posX));
        posY = fmax(-1., fmin(1., posY));
        gModelObject->ScrollAction(dX, dY, posX, posY);
    }
    return;
}


void scroll_callback(GLFWwindow* window, double x, double y)
{
    printf("scroll, x=%f, y=%f\n", x, y);
    float scale = 1.0f;
    if( y > 0 ){
        scale = 1.11;
    }
    else if( y < 0)
    {
      scale = 0.89;
    }

    gModelObject->ScaleAction(scale);
    return;
}


int main(int argc, char **argv)
{
    GLFWwindow *window;

    glfwSetErrorCallback(error_callback);

    if (!glfwInit())
        exit(EXIT_FAILURE);

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 2);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 0);

    window = glfwCreateWindow(gWidth, gHeith, "AssimpModel", NULL, NULL);

    if (!window) {
        glfwTerminate();
        exit(EXIT_FAILURE);
    }

    glfwSetKeyCallback(window, key_callback);
    glfwSetMouseButtonCallback(window, mouse_button_callback);
    glfwSetCursorPosCallback(window, cursor_position_callback);
    glfwSetScrollCallback( window, scroll_callback);

    glfwMakeContextCurrent(window);
    gladLoadGLLoader((GLADloadproc) glfwGetProcAddress);
    glfwSwapInterval(1);

    // NOTE: OpenGL error checks have been omitted for brevity

    gModelObject = new ModelObject();
    gModelObject->PerformGLInits();
    gModelObject->SetViewport( gWidth * 2, gHeith * 2 );

    while (!glfwWindowShouldClose(window)) {
        int width, height;
        glfwGetFramebufferSize(window, &width, &height);


        gModelObject->Render();

        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glfwDestroyWindow(window);

    glfwTerminate();
    exit(EXIT_SUCCESS);
    return 0;
}

