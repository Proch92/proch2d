#include "proch2d.h"

Image::Image(char *filename) {
	int depth;

	data = stbi_load(filename, &w, &h, &depth, 4);

	if(data == NULL)
		printf("error loading image through stb_image: NULL returned\n");
	else {
		printf("image loaded: w=%d, h=%d, d=%d\n", w, h, depth);

		glGenTextures(1, &tex);

		glBindTexture(GL_TEXTURE_2D, tex);

		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
	    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, w, h, 0, GL_RGBA, GL_UNSIGNED_BYTE, data);
	}
}

Image::~Image() {
	free(data);
}

void Image::bindTexture() {
	glBindTexture(GL_TEXTURE_2D, tex);
}

glm::vec2 Image::getSize() {
	return glm::vec2(w, h);
}