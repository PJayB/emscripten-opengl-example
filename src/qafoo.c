#include <stdio.h>
#include <GLFW/glfw3.h>
#include "window.h"

void initGlScene();
void renderGlScene(double delta);
void doRenderingLoop(void (*)());

double lastSceneRendered, currentSceneRendered;

GLFWwindow* gGlfwWindow = NULL;

void renderFrame() {
    currentSceneRendered = glfwGetTime();
    renderGlScene(currentSceneRendered - lastSceneRendered);
    lastSceneRendered = currentSceneRendered;
    glfwSwapBuffers(gGlfwWindow);
}

int main(void)
{
    /* Initialize the library */
    if (!glfwInit()) {
        printf("Could not initialize library\n");
        return -1;
    }
 
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 2);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 0);

    /* Create a windowed mode window and its OpenGL context */
    if(!(gGlfwWindow = glfwCreateWindow(640, 480, "GLFW", NULL, NULL)))
    {
        printf("Could not create OpenGL window\n");
        glfwTerminate();
        return -1;
    }

    glfwMakeContextCurrent(gGlfwWindow);
    glfwSwapInterval(1);

    initGlScene();
    lastSceneRendered = glfwGetTime();

    doRenderingLoop(&renderFrame);

    glfwDestroyWindow(gGlfwWindow);
    glfwTerminate();
    return 0;
}
