#include "stdio.h"

//glew
#define GLEW_STATIC
#include <GL/glew.h>

//glfw
#include "GLFW/glfw3.h"

//glm libraries
#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"
#include "glm/gtc/type_ptr.hpp"

//stb image loader
#include "stb_image.h"

//proch2d
#include "/home/proch/proch2d/src/Image.h"
#include "/home/proch/proch2d/src/Window.h"

GLuint p2dLoadShaderProgram(const char* vertexFile, const char* fragmentFile);
void load_shader(const char* filename, GLuint shd);
GLuint p2dCreateQuadVBO();