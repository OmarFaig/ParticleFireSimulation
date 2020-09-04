#pragma once
#include<SDL.h>
namespace game1 {
	class Screen {
	public:
		const static int SCREEN_WIDTH = 1000;
		const static int SCREEN_HEIGHT =800;
	private://m_ member variable
		SDL_Window *m_window;
		SDL_Renderer *m_renderer;
		SDL_Texture *m_texture;
		Uint32 *m_buffer;
		Uint32 *m_buffer2;

	public:
		Screen();
		bool init();
		bool processEvents();
		void close();
		void update();
		void setPixel(int x, int y, Uint8 red, Uint8 green, Uint8 blue);
		void clear();
		void boxBlur();
	};
}

