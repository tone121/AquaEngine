#include <graphics/Display.h>

Display::Display(int w, int h, const std::string& title) : Close(false)
{
	SDL_Init(SDL_INIT_EVERYTHING);

	SDL_GL_SetAttribute(SDL_GL_RED_SIZE, 8);
	SDL_GL_SetAttribute(SDL_GL_GREEN_SIZE, 8);
	SDL_GL_SetAttribute(SDL_GL_BLUE_SIZE, 8);
	SDL_GL_SetAttribute(SDL_GL_ALPHA_SIZE, 8);
	SDL_GL_SetAttribute(SDL_GL_BUFFER_SIZE, 32);

	SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);

	m_Window = SDL_CreateWindow(title.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, w, h, SDL_WINDOW_OPENGL);
	m_OpenGLContext = SDL_GL_CreateContext(m_Window);
}

Display::~Display()
{
	SDL_GL_DeleteContext(m_OpenGLContext);
	SDL_DestroyWindow(m_Window);
}

void Display::Update()
{
	SDL_GL_SwapWindow(m_Window);

	while(SDL_PollEvent(&m_InputEvent)) {
		//TODO: Key Input Too!
		if(m_InputEvent.type == SDL_QUIT)
			Close = true;
	}
}

SDL_Window* Display::GetWindow()
{
	return m_Window;
}
