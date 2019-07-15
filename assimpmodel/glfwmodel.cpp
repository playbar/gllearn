#include "linmath.h"

#include <stdlib.h>
#include <stdio.h>
#include "ModelObject.h"


ModelObject *gModelObject =NULL;
bool bleftpress = false;
bool brightpress = false;

GLint gWidth = 480;
GLint gHeith = 320;

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

//        printf("dx =%f, dy = %f \n", posx, posy);
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


//这个是窗口变化的回调函数。。注意输入参数
//是一个glfw的窗口，一个宽度和高度
void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{

    gModelObject->SetViewport( width, height );
//    glViewport(0, 0, width, height);//这个是回调函数内的内容
    //这里是将视口改成变化后的的窗口大小
    //注意需要的注册该回调函数
    //glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
    //两个参数是，glfw的窗口以及回调函数
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
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);//注册函数，该函数还可以注册其他相关硬件的回调函数

    glfwMakeContextCurrent(window);
    gladLoadGLLoader((GLADloadproc) glfwGetProcAddress);
    glfwSwapInterval(1);

    // NOTE: OpenGL error checks have been omitted for brevity

    int maxVertexAttribs = 0;
    int maxVertexUniformVectors = 0;
    int maxVaryingVectors = 0;
    int maxCombinedTextureImageUnits = 0;
    int maxVertexTextureImageUnits = 0;
    int maxTextureImageUnits = 0;
    int maxFragmentUniformVectors = 0;
    int maxTextureSize = 0;
    glGetIntegerv(GL_MAX_VERTEX_ATTRIBS, &maxVertexAttribs);
//    glGetIntegerv(GL_MAX_VERTEX_UNIFORM_VECTORS, &maxVertexUniformVectors);
//    glGetIntegerv(GL_MAX_VARYING_VECTORS, &maxVaryingVectors);
    glGetIntegerv(GL_MAX_COMBINED_TEXTURE_IMAGE_UNITS, &maxCombinedTextureImageUnits);
    glGetIntegerv(GL_MAX_VERTEX_TEXTURE_IMAGE_UNITS, &maxVertexTextureImageUnits);
    glGetIntegerv(GL_MAX_TEXTURE_IMAGE_UNITS, &maxTextureImageUnits);
//    glGetIntegerv(GL_MAX_FRAGMENT_UNIFORM_VECTORS, &maxFragmentUniformVectors);
    glGetIntegerv(GL_MAX_TEXTURE_SIZE, &maxTextureSize);

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

