#include <stdio.h>
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <tinycthread/source/tinycthread.h>
#include "gui.h"
#include "old_main.h"

using namespace Konstructs;

int main(int argc, char **argv) {

    if (glfwInit() == GL_FALSE) {
        printf("Failed to init glfw");
        return -1;
    }

    Window* win = new Window();

    if (!win->is_ok()) {
        glfwTerminate();
        return -1;
    }

    while (!glfwWindowShouldClose(win->get())) {
        // Do stuff ...
    }

    glfwTerminate();
    delete win;
    printf("All OK!\n");
    return 0;
}
