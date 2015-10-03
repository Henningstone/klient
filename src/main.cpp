#include <stdio.h>
#include <GL/glew.h>
#include <GLFW/glfw3.h>

int main(int argc, char **argv) {

    if (glfwInit() == GL_FALSE) {
        printf("Failed to init glfw");
        return -1;
    }

    GLFWwindow* window = glfwCreateWindow(640, 480, "My Title", NULL, NULL);
    if (!window) {
        glfwTerminate();
        return -1;
    }

    while (!glfwWindowShouldClose(window)) {}

    glfwDestroyWindow(window);
    glfwTerminate();
    printf("All OK!\n");
    return 0;
}
