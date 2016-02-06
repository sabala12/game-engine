#ifndef GAME_ENGINE_DISPLAY_H
#define GAME_ENGINE_DISPLAY_H

#pragma comment(lib, "SDL2.lib")
#pragma comment(lib, "SDL2main.lib")
#include <SDL2/SDL.h>

#include <string>

namespace Engine
{
	struct DisplayData;

	class Display
	{
	public:
		Display(const DisplayData& displayData);
		virtual ~Display();
		
		void Clear(float r, float g, float b, float a);
		void SwapBuffers();
	
		void operator=(const Display& display) = delete;
		Display(const Display& display) = delete;
		
	private:
		SDL_Window* m_window;
		SDL_GLContext m_glContext;
	};

}

#endif //GAME_ENGINE_DISPLAY_H