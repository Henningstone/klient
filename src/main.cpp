#include <stdio.h>
#include <GL/glew.h>
#include <GLFW/glfw3.h>

namespace Konstructs {

    class Window {
        GLFWwindow* window;

        public:

        Window() {
            window = glfwCreateWindow(640, 480, "My Title", NULL, NULL);
        }

        ~Window() {
            glfwDestroyWindow(window);
        }

        int is_ok() {
            if (window) return 1;
            return 0;
        }

        GLFWwindow* get() {
            return window;
        }
    };

}

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
