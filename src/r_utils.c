#include "r_utils.h"

void prepare_scene(void)
{
        for (int y = 0; y < SH; ++y){
                for (int x = 0; x < SW; ++x){
                        game.pix[x + y * SW] = 0x0;
                }
        }
}

int 
get_color(int c)
{
        if(c==0){ return 16776960;} //Yellow	
        if(c==1){ return 10526720;} //Yellow darker	
        if(c==2){ return 65280;} //Green	
        if(c==3){ return 40960;} //Green darker	
        if(c==4){ return 65535;} //Cyan	
        if(c==5){ return 41120;} //Cyan darker
        if(c==6){ return 10511360;} //brown	
        if(c==7){ return 7221760;} //brown darker
        if(c==8){ return 15490;} //background 
}

void
pixel(const int x, const int y, const int c)
{
        game.pix[x + y * SW] = c;
}

void present_scene(void)
{
        SDL_RenderClear(game.ren);
        SDL_UpdateTexture(game.tex, NULL, game.pix, SW * 4);
        SDL_RenderCopy(game.ren, game.tex, NULL, NULL);
        SDL_RendererFlip flip = SDL_FLIP_VERTICAL;
        SDL_RenderCopyEx(game.ren, game.tex, NULL, NULL, 0, NULL, flip);
        SDL_RenderPresent(game.ren);
}