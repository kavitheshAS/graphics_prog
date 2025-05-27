#include <GL/glew.h>
#include <GLFW/glfw3.h>

int main() {
    if (!glfwInit()) return -1;

    GLFWwindow* window = glfwCreateWindow(800, 600, "OpenGL Triangle", NULL, NULL);
    if (!window) { glfwTerminate(); return -1; }

    glfwMakeContextCurrent(window);
    glewExperimental = true;
    if (glewInit() != GLEW_OK) return -1;

    while (!glfwWindowShouldClose(window)) {
        glClear(GL_COLOR_BUFFER_BIT);
        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glfwDestroyWindow(window);
    glfwTerminate();
    return 0;
}
