#include "proch2d.h"

GLuint p2dCreateQuadVBO() {
	//create the "box" vbo
	float vertices[] = {
	     0.0f, 0.0f,
	     1.0f, 0.0f,
	     1.0f, 1.0f,

	     1.0f, 1.0f,
	     0.0f, 1.0f,
	     0.0f, 0.0f
	};
	GLuint vbo;
	glGenBuffers(1, &vbo);
	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

	return vbo;
}

GLuint p2dLoadShaderProgram(const char* vertexFile, const char* fragmentFile) {
	GLuint vertex_shd = glCreateShader(GL_VERTEX_SHADER);
	load_shader(vertexFile, vertex_shd);
	
	GLuint fragment_shd = glCreateShader(GL_FRAGMENT_SHADER);
	load_shader(fragmentFile, fragment_shd);

	GLuint shaderProgram = glCreateProgram();
	glAttachShader(shaderProgram, vertex_shd);
	glAttachShader(shaderProgram, fragment_shd);
	glBindFragDataLocation(shaderProgram, 0, "outColor");
	glLinkProgram(shaderProgram);
	glUseProgram(shaderProgram);
	printf("shader program created\n");

	return shaderProgram;
}

void load_shader(const char* filename, GLuint shd) {
	FILE *file;
	
	file = fopen(filename, "r");
	if(file == NULL) {
		printf("failed to load shader\n");
		return;
	}
	
	fseek(file, 0, SEEK_END);
	long int size = ftell(file);
	fseek(file, 0, SEEK_SET);
	
	GLchar* sourceBuffer = (GLchar*) new char[size+1];

	fread(sourceBuffer, 1, size, file);
	sourceBuffer[size] = 0;

	fclose(file);

	glShaderSource(shd, 1, (const GLchar**) &sourceBuffer, NULL);
	glCompileShader(shd);

	GLint status;
	glGetShaderiv(shd, GL_COMPILE_STATUS, &status);
	if(status != GL_TRUE) {
		printf("failed to compile shader\n");
	}
	char buffer[512];
	glGetShaderInfoLog(shd, 512, NULL, buffer);
	if(buffer[0] != '\0') printf("%s\n", buffer);
}