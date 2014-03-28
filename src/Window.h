class Window{
public:
	Window();
	Window(int windowSizeW, int windowSizeH);
	Window(int windowSizeW, int windowSizeH, const char* windowName);
	~Window();
	void makeContext();
	GLFWwindow* glfwWindow;
private:
	int width, height;
};

