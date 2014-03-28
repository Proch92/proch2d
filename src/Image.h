class Image{
public:
	Image(char*);
	~Image();
	glm::vec2 getSize();

	void bindTexture();
private:
	int w, h;
	unsigned char *data;

	GLuint tex;
};

