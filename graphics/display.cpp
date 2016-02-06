#include "graphics/display.h"
#include "common_structs/display_data.h"

#include <GL/glew.h>
#include <iostream>

namespace Engine
{
	Display::Display(const DisplayData& displayData)
	{
		SDL_Init(SDL_INIT_EVERYTHING);

		SDL_GL_SetAttribute(SDL_GL_RED_SIZE, 8);
		SDL_GL_SetAttribute(SDL_GL_GREEN_SIZE, 8);
		SDL_GL_SetAttribute(SDL_GL_BLUE_SIZE, 8);
		SDL_GL_SetAttribute(SDL_GL_ALPHA_SIZE, 8);
		SDL_GL_SetAttribute(SDL_GL_BUFFER_SIZE, 32);
		SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 16);
		SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);

		m_window = SDL_CreateWindow(displayData.m_title.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
									displayData.m_width, displayData.m_height, SDL_WINDOW_OPENGL);
		m_glContext = SDL_GL_CreateContext(m_window);

		GLenum res = glewInit();
		if (res != GLEW_OK)
		{
			std::cerr << "Glew failed to initialize!" << std::endl;
		}

		//glEnable(GL_DEPTH_TEST);

		// optimaze for pixel depth, 
		//diceds what to render based on camera direction
		//glEnable(GL_CULL_FACE);
		//glCullFace(GL_BACK);

		// use transparecy
		//glEnable(GL_BLEND);
		//glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

		glewInit();

		// Allow depth propertie to fragments
	}

	Display::~Display()
	{
		SDL_GL_DeleteContext(m_glContext);
		SDL_DestroyWindow(m_window);
		SDL_Quit();
	}

	void Display::Clear(float r, float g, float b, float a)
	{
		glClearColor(r, g, b, a);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	}

	void Display::SwapBuffers()
	{
		SDL_GL_SwapWindow(m_window);
	}
}