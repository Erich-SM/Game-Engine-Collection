#include "i_input.h"

static void
read_keys()
{
        SDL_PumpEvents();
        game.inkeys = SDL_GetKeyboardState(NULL);
}

static int
key_down(Uint8 key)
{
        if(!game.inkeys) return 0;
        return (game.inkeys[key] != 0);
}

void do_input(void)
{
        // convert to mouse stuff
	read_keys();
               /* mouse aiming */
        int x,y;
        SDL_GetRelativeMouseState(&x,&y);
        //int yaw = y;
        P.a += x * 0.4;
       // yaw          = clamp(yaw - y*0.4, -5, 5);
        //P.i   = yaw - P.z*0.4;
        if(P.a < 0) P.a += MA;
        if(P.a > MA-1) P.a -= MA;
        int dx = A.sin[P.a] * 11.0;
        int dy = A.cos[P.a] * 11.0;
        if(key_down(SDL_SCANCODE_A)){ P.x -= dy; P.y += dx; } // look left
        if(key_down(SDL_SCANCODE_D)){ P.x += dy; P.y -= dx; } // look right
        if(key_down(SDL_SCANCODE_W)){ P.x += dx; P.y += dy; } // move forward
        if(key_down(SDL_SCANCODE_S)){ P.x -= dx; P.y -= dy; } // move backward
        if(key_down(SDL_SCANCODE_UP)){ P.i -= 1; } // float up
        if(key_down(SDL_SCANCODE_DOWN)){ P.i += 1; } // float down
        if(key_down(SDL_SCANCODE_SPACE)) {P.z += 4;}
        if(key_down(SDL_SCANCODE_LSHIFT)) {P.z -= 4;}
	if(key_down(SDL_SCANCODE_Q)) { exit(0); }
}
