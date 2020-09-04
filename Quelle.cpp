#include<iostream>
#include<SDL.h>
#include"Screen.h"
#include<math.h>
#include<stdlib.h>
#include<time.h>
#include"Swarn.h"

using namespace std;
using namespace  game1;

// int main (int argc, char *argv[]) ist wichtig in VS

int main(int argc, char*argv[]) {
	srand(time(NULL));

	Screen screen;
	if (screen.init()== false) {
		cout <<"Error" << endl;
	}
	Swarn swarn;

	//draw particles



	//game loop
	
	while (true) {
		int elapsed = SDL_GetTicks();
		
		swarn.update(elapsed);
		unsigned char green = (unsigned char)((1 + sin(elapsed*0.0001)) * 128);
		unsigned char red = (unsigned char)((1 + sin(elapsed*0.0002)) * 128);
		unsigned char blue = (unsigned char)((1 + sin(elapsed*0.0003)) * 128);

		const Particle *const pParticles = swarn.getParticles();

		for (int i = 0; i < Swarn::NPARTICLES; i++) {
			Particle particle = pParticles[i];

			int x = (particle.m_x+1)*Screen::SCREEN_WIDTH/2;
			int y = particle.m_y *Screen::SCREEN_HEIGHT / 2+ Screen::SCREEN_HEIGHT / 2;

			screen.setPixel(x, y, red, green, blue);
		}
		screen.boxBlur();

		
	
		/*for (int y = 0; y < Screen::SCREEN_HEIGHT; y++) {
			for (int x = 0; x < Screen::SCREEN_WIDTH; x++) {
				screen.setPixel(x, y, red, green, blue);
			}
		}*/
		
		//draw Screen
		screen.update();
		if (screen.processEvents() == false) {
			break;
		}
		

	}
	//SDL_Delay(5000);
	screen.close();

	//SDL_Quit();
   //destroy SDL
	
	
	return 0;
}