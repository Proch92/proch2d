#include "proch2d.h"

Window::Window() {
	Window(640, 480, "proch2d window");
}

Window::Window(int w, int h) {
    Window(w, h, "proch2d window");
}

Window::Window(int w, int h, const char *name) {
    glfwWindow = glfwCreateWindow(w, h, name, NULL, NULL);
    if (!glfwWindow) {
        glfwTerminate();
        printf("could not create a window: glfwCreateWindow() returned NULL\n");
    }
    else {
        glfwGetFramebufferSize(glfwWindow, &width, &height);
        glViewport(0, 0, width, height);
    }
}

Window::~Window() {
	
}

void Window::makeContext() {
	glfwMakeContextCurrent(glfwWindow);
}