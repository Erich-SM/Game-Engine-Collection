#include "common.h"

extern void pixel(const int x, const int y, const int c);
extern int get_color(int c);
extern int dist(int x1, int y1, int x2, int y2);
extern void present_scene();

extern uint32_t W_textures[8][TXH * TXW];

extern Player P;
extern Angles A;

extern Sectors S[30];
extern Walls W[30];