#include <graphics/Graphics.h>

Graphics::Graphics(Display& display)
{
	m_Display = &display;

	// Initializing GLEW
	glewExperimental = true;
	GLenum code = glewInit();
	if(code != GLEW_OK)
		std::cout << "Error initializing GLEW: " << glewGetErrorString(code) << std::endl;

	// Setup OpenGL Transparency
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
}

void Graphics::Clear(float r, float g, float b)
{
	glClearColor(r, g, b, 255.0f);
	glClear(GL_COLOR_BUFFER_BIT);
}
