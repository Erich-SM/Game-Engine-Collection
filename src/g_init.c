#include "g_init.h"


//---center tube---
// 5 28
int load_sectors[]=
{
0,4,    0,6, 3,1,
4,12, -12,6, 6,1,
12,16,  0,6, 3,1,
16,20,  0,6, 3,1,
20,28, 32,50, 0,1,
};

int load_walls[]=
{
112,120, 136,144, 0,
136,144, 136,184, 1,
136,184, 112,208, 0,
112,208, 112,120, 1,
152,168, 152,160, 2,
152,160, 160,152, 3,
160,152, 168,152, 7,
168,152, 176,160, 3,
176,160, 176,168, 2,
176,168, 168,176, 3,
168,176, 160,176, 7,
160,176, 152,168, 3,
192,144, 216,120, 4,
216,120, 216,208, 5,
216,208, 192,184, 4,
192,184, 192,144, 5,
136,184, 192,184, 7,
192,184, 216,208, 7,
216,208, 112,208, 6,
112,208, 136,184, 7,

160,152, 168,152, 7,
168,152, 176,160, 3,
176,160, 176,168, 2,
176,168, 168,176, 3,
168,176, 160,176, 7,
160,176, 152,168, 3,
152,168, 152,160, 2,
152,160, 160,152, 3,
};

/*
uint32_t
load_sectors[] =
{
        0,  4,  0, 40, 2, 3,
        4,  8,  0, 40, 4, 5,
        8,  12, 0, 40, 6, 7,
        12, 16, 0, 40, 0, 1,
};

uint32_t
load_walls[] = 
{
        0, 0, 32, 0, 0,
        32, 0, 32, 32, 1,
        32, 32, 0, 32, 0,
        0, 32, 0, 0, 1,

        64, 0, 96, 0, 2,
        96, 0, 96, 32, 3,
        96, 32, 64, 32, 2,
        64, 32, 64, 0, 3,

        64, 64, 96, 64, 4,
        96, 64, 96, 96, 5,
        96, 96, 64, 96, 4,
        64, 96, 64, 64, 5,

        0, 64, 32, 64, 6,
        32, 64, 32, 96, 7,
        32, 96, 0, 96, 6,
        0, 96, 0, 64, 7,
};
*/

/*
//---doom level---
int load_sectors[]=
{
0,8, 40,50, 9,9,
8,16, 0,40, 6,6,
16,24, 80,110, 0,0,
24,28, 0,30, 6,6,
28,32, 0,20, 6,6,
32,36, 0,10, 6,6,
36,40, 0,30, 5,5,
40,44, 0,30, 5,5,
44,48, 30,110, 0,0,
48,52, 30,110, 0,0,
};

int load_walls[]=
{
160,228, 168,228, 4,
168,228, 176,236, 5,
176,236, 176,244, 4,
176,244, 168,252, 5,
168,252, 160,252, 4,
160,252, 152,244, 5,
152,244, 152,236, 4,
152,236, 160,228, 5,
104,224, 152,184, 1,
152,184, 176,184, 3,
176,184, 224,224, 1,
224,224, 224,256, 0,
224,256, 192,288, 1,
192,288, 136,288, 0,
136,288, 104,256, 1,
104,256, 104,224, 0,
104,224, 152,184, 1,
152,184, 176,184, 0,
176,184, 224,224, 1,
224,224, 224,256, 0,
224,256, 192,288, 1,
192,288, 136,288, 0,
136,288, 104,256, 1,
104,256, 104,224, 0,
152,168, 176,168, 2,
176,168, 176,184, 3,
176,184, 152,184, 2,
152,184, 152,168, 3,
152,152, 176,152, 2,
176,152, 176,168, 3,
176,168, 152,168, 2,
152,168, 152,152, 3,
152,136, 176,136, 2,
176,136, 176,152, 3,
176,152, 152,152, 2,
152,152, 152,136, 3,
208,160, 208,136, 5,
208,136, 232,136, 4,
232,136, 232,160, 5,
232,160, 208,160, 4,
96,136, 120,136, 4,
120,136, 120,160, 5,
120,160, 96,160, 4,
96,160, 96,136, 5,
216,144, 224,144, 4,
224,144, 224,152, 5,
224,152, 216,152, 4,
216,152, 216,144, 5,
104,144, 112,144, 4,
112,144, 112,152, 5,
112,152, 104,152, 4,
104,152, 104,144, 5,
};
*/
 
void
init_secswalls()
{
        int v1 = 0, v2 = 0;
        for(int s = 0; s < NS; s++){
                S[s].ws = load_sectors[v1 + 0]; // load start of wall
                S[s].we = load_sectors[v1 + 1]; // load end of wall
                S[s].z1 = load_sectors[v1 + 2]; // load bottom height
                S[s].z2 = load_sectors[v1 + 3] - load_sectors[v1 + 2]; // load top height
                S[s].c1 = load_sectors[v1 + 4]; // load bottom color
                S[s].c2 = load_sectors[v1 + 5]; // load top color
                v1+=6; // increment sector
                for(int w = S[s].ws; w < S[s].we; w++){
                        W[w].x1 = load_walls[v2 + 0]; // load wall X
                        W[w].y1 = load_walls[v2 + 1]; // load wall Y
                        W[w].x2 = load_walls[v2 + 2]; // load wall x2
                        W[w].y2 = load_walls[v2 + 3]; // load wall Y2
                        W[w].c  = load_walls[v2 + 4]; // load wall color
                        v2 += 5; // increment wall
                }
        }
}

void
init_textures()
{
        /*
        for(int i = 0; i < 8; i++){
                W_textures[i] = (uint32_t*)malloc(TXW * TXH);
        }
        */
        for(int x = 0; x < TXW; x++){
                for(int y = 0; y < TXH; y++){
                        int xorcolor = (x * 256 / TXW) ^ (y * 256 / TXH);
                        //int xcolor = x * 256 / texWidth;
                        int ycolor = y * 256 / TXH;
                        int xycolor = y * 128 / TXH + x * 128 / TXW;
                        W_textures[0][TXW * y + x] = 65536 * 254 * (x != y && x != TXW - y); //flat red texture with black cross
                        W_textures[1][TXW * y + x] = xycolor + 256 * xycolor + 65536 * xycolor; //sloped greyscale
                        W_textures[2][TXW * y + x] = 256 * xycolor + 65536 * xycolor; //sloped yellow gradient
                        W_textures[3][TXW * y + x] = xorcolor + 256 * xorcolor + 65536 * xorcolor; //xor greyscale
                        W_textures[4][TXW * y + x] = 256 * xorcolor; //xor green
                        W_textures[5][TXW * y + x] = 65536 * 192 * (x % 16 && y % 16); //red bricks
                        W_textures[6][TXW * y + x] = 65536 * ycolor; //red gradient
                        W_textures[7][TXW * y + x] = 128 + 256 * 128 + 65536 * 128; //flat grey texture
                }
        }

        printf("%i\n", W_textures[1][1490]);
}

void
init_player()
{
        for(int x = MA; x--;){
                // convert to integer
                A.cos[x] = cos(x/180.0*M_PI);
                A.sin[x] = sin(x/180.0*M_PI);
        }

        P.x = 70; P.y = -110; P.z = 20; P.a = 0; P.i = 0;
}

void init(void)
{
        SDL_Init(SDL_INIT_VIDEO | SDL_INIT_EVENTS | SDL_INIT_TIMER);
        game.win = SDL_CreateWindow("RPC Authority", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SW*R, SH*R, 0); // create window
        game.ren = SDL_CreateRenderer(game.win, -1, SDL_RENDERER_PRESENTVSYNC);
        SDL_RenderSetLogicalSize(game.ren, SW, SH);
        SDL_RenderSetIntegerScale(game.ren, 1);
        game.tex = SDL_CreateTexture(game.ren, SDL_PIXELFORMAT_ABGR8888, SDL_TEXTUREACCESS_STREAMING, SW, SH);
        game.pix = malloc(SW * SH * 4); // initialize the pix array, could point to texture array too

        SDL_SetRelativeMouseMode(SDL_TRUE);

        init_player(); // init angles and player loc

        init_secswalls(); // init sectors and walls

        init_textures();
}

void cleanup(void)
{
        /*
        for(int i = 0; i < 8; i++){
                free(W_textures[i]);
        }
        */
        SDL_DestroyTexture(game.tex);
        SDL_DestroyRenderer(game.ren);
        SDL_DestroyWindow(game.win);
        free(game.pix); // incase of textures working uncomment this
        SDL_Quit();
}