#include "simple.h"

#include "linmath.h"

#include <stdlib.h>
#include <stdio.h>
#include "modelAssimp.h"


ModelAssimp *gAssimpObject =NULL;
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
        float posx = dx * 2 / gAssimpObject->GetScreenWidth();
        float posy = -dy * 2 / gAssimpObject->GetScreenHeight();

        printf("dx =%f, dy = %f \n", posx, posy);
        gAssimpObject->MoveAction(posx, posy);
    }
    if( brightpress )
    {
        float dX = -(float) dx / gAssimpObject->GetScreenWidth();
        float dY = (float) dy / gAssimpObject->GetScreenHeight();
        float posX = 2* x / gAssimpObject->GetScreenWidth() - 1.0;
        float posY = -2* y / gAssimpObject->GetScreenHeight() + 1.0;
        posX = fmax(-1., fmin(1., posX));
        posY = fmax(-1., fmin(1., posY));
        gAssimpObject->ScrollAction(dX, dY, posX, posY);
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

    gAssimpObject->ScaleAction(scale);
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

    gAssimpObject = new ModelAssimp();
    gAssimpObject->PerformGLInits();
    gAssimpObject->SetViewport( gWidth * 2, gHeith * 2 );

    while (!glfwWindowShouldClose(window)) {
        int width, height;
        glfwGetFramebufferSize(window, &width, &height);


        gAssimpObject->Render();

        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glfwDestroyWindow(window);

    glfwTerminate();
    exit(EXIT_SUCCESS);
    return 0;
}

