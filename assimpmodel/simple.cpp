#include "simple.h"

#include "linmath.h"

#include <stdlib.h>
#include <stdio.h>
#include "modelAssimp.h"


ModelAssimp *gAssimpObject =NULL;
bool bpress = false;

GLint gWidth = 640;
GLint gHeith = 480;

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
    if (button != GLFW_MOUSE_BUTTON_LEFT)
        return;

    printf("button = %d, action=%d, mods = %d\n", button, action, mods );

    if (action == GLFW_PRESS)
    {
        bpress = true;
//        gAssimpObject->DoubleTapAction();
    }
    else if( GLFW_RELEASE == action )
    {
        bpress = false;
    }
    else
    {
    }
}

void cursor_position_callback(GLFWwindow* window, double x, double y)
{

    float dX = x / gAssimpObject->GetScreenWidth();
    float dY = -y / gAssimpObject->GetScreenHeight();
    printf("dx =%f, dy = %f \n", dX, dY);

//    if( bpress ) {
//        float dX = x / gAssimpObject->GetScreenWidth();
//        float dY = -y / gAssimpObject->GetScreenHeight();
//        gAssimpObject->MoveAction(dX, dY);
//    }
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

    glfwMakeContextCurrent(window);
    gladLoadGLLoader((GLADloadproc) glfwGetProcAddress);
    glfwSwapInterval(1);

    // NOTE: OpenGL error checks have been omitted for brevity

    gAssimpObject = new ModelAssimp();
    gAssimpObject->PerformGLInits();
    gAssimpObject->SetViewport( gWidth, gHeith );

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

