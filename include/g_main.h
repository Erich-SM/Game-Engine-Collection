#include "common.h"

extern void cleanup(void);
extern void do_input(void);
extern void init(void);
extern void prepare_scene(void);
extern void draw_3d(void);
extern void present_scene(void);

uint32_t W_textures[8][TXH * TXW];

Game game;
Player P;
Angles A;
Sectors S[30];
Walls W[30];