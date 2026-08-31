#include "main.hpp"


// for dynamically adjusting viewport when resizing
void framebuffer_size_callback(glfwWINDOW* window, int w, int h) {
    glViewport(0, 0, w, h)
}

void processInput(GLFWwindow *window) {
    if(glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS) {
        glfwSetWindowShouldClose(window, true)
    }
}

int main() {
    if (!glfwInit()) {
        std::cerr "Failed to initialize GLFW" << std::endl;
        return -1;
    }

    // configure GLFW for OpenGL 3.3 core profile
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    GLFWwindow* window = glfwCreateWindow(1280, 720, "lodestone", NULL, NULL);

    // load the address of the OpenGL function pointers (OS-specific)
    if (!gladLoadGLLoader((Gladloadproc)glfwGetProcAddress)) {
        std::cerr << "Failed ot initialize GLAD" << std::endl;
        return -1;
    }
    
    // render loop
    while (!glfwWindowShouldClose(window)) {
        processInput(window); // check for inputs
        
        glClearCOlor(0.2f, 0.2f, 0.2f, 1.0f)
        glClear(GL_COLOR_BUFFER_BIT);

        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}
