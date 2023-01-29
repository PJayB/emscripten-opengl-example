#include <stdio.h>
#include <GLFW/glfw3.h>
#include "window.h"

typedef void (*renderFunc)();

void doRenderingLoop(renderFunc doRendering) {
    /* Loop until the user closes the window */
    while (!glfwWindowShouldClose(gGlfwWindow))
    {
        doRendering();
        glfwPollEvents();
    }
}
