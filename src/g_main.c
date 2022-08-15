#include "g_main.h"

// this is the most minimal FPS implementation i have found
static unsigned int
time_left(const unsigned int next_time)
{
        const unsigned int now = SDL_GetTicks();

        if(next_time <= now){
                return 0;
        } else {
                return next_time - now;
        }
}

int main(int argc, char *argv[])
{
	memset(&game, 0, sizeof(Game));
	
	init();
	
	atexit(cleanup);

        unsigned int next_time = SDL_GetTicks() + T; // set up ticks
	
	while (1){
		prepare_scene();

		do_input();

		
		draw_3d();

                present_scene();
		
		//SDL_Delay(time_left(next_time));
		//next_time += T;
	}

	return 0;
}