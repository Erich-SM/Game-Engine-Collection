#include "r_world.h"

void
draw_wall(int x1, int x2, int b1, int b2, int t1, int t2, int c, int s)
{
        int y;
        int dyb = b2 - b1; 
        int dyt = t2 - t1; 
        int dx = x2 - x1; if(dx == 0) dx = 1;
        int xs = x1;

        if(x1 < 1) x1 = 1;
        if(x2 < 1) x2 = 1;
        if(x1 > SW - 1) x1 = SW - 1;
        if(x2 > SW - 1) x2 = SW - 1;

        for(int x = x1; x < x2; x++){
                //SDL_Delay(1);
                int y1 = dyb * (x - xs + 0.5) / dx+b1;
                int y2 = dyt * (x - xs + 0.5) / dx+t1;
                if(y1 < 1) y1 = 1;
                if(y2 < 1) y2 = 1;
                if(y1 > SH - 1) y1 = SH - 1;
                if(y2 > SH - 1) y2 = SH - 1;

                if(S[s].surface == 1) { S[s].surf[x] = y1; continue;}
                if(S[s].surface == 2) { S[s].surf[x] = y2; continue;}
                if(S[s].surface ==-1) { 
                        for(y=S[s].surf[x];y<y1;y++){
                                pixel(x, y, get_color(S[s].c1));
                        }
                }
                if(S[s].surface ==-2) { 
                        for(y=y2;y<S[s].surf[x];y++){
                                pixel(x, y, get_color(S[s].c2));
                        }
                }
                /*
                int lineHeight = (S[s].z2 - S[s].z1);
                int step = 1 * TXH / lineHeight;
                int texPos = (S[s].ws - SH / 2 + lineHeight / 2) * step;
                */
                for(int y = y1; y < y2; y++){
                        /*
                        int texY = texPos & (TXH - 1);
                        texPos += step;
                        uint32_t color = W_textures[3][TXH * texY + x];
                        */
                        pixel(x, y, c);
                }
        }
}

void
clip_behind(int *x1, int *y1, int *z1, int x2, int y2, int z2)
{
        float da = *y1;
        float db = y2;
        float d = da - db; if(d == 0) d = 1;
        float s = da / (da - db);
        *x1 = *x1 + s*(x2 - (*x1));
        *y1 = *y1 + s*(y2 - (*y1)); if(*y1==0) *y1 = 1;
        *z1 = *z1 + s*(z2 - (*z1));
}

void
draw_3d()
{
        int wx[4], wy[4], wz[4]; float CS=A.cos[P.a]; float SN=A.sin[P.a];

        for(int s = 0; s<NS -1; s++){
                for(int w = 0; w < NS - s - 1; w++){
                        if(S[w].d < S[w+1].d){
                                Sectors st = S[w]; S[w]=S[w+1]; S[w+1]=st;
                        }
                }
        }

        for(int s = 0; s<NS; s++){
                S[s].d = 0;   
                if(P.z < S[s].z1) { S[s].surface=1;}
                else if(P.z > S[s].z2) { S[s].surface=2;}
                else { S[s].surface = 0;}
                for(int loop = 0; loop < 2; loop++){
                        for(int w = S[s].ws; w < S[s].we; w++){
                                int x1 = W[w].x1 - P.x, y1 = W[w].y1 - P.y;
                                int x2 = W[w].x2 - P.x, y2 = W[w].y2 - P.y;
                                if(loop == 0) {
                                        int swp = x1; x1 = x2; x2 = swp; swp = y1; y1 = y2; y2=swp;
                                }

                                wx[0] = x1 * CS - y1 * SN;
                                wx[1] = x2 * CS - y2 * SN;
                                wx[2] = wx[0];
                                wx[3] = wx[1];

                                wy[0] = y1 * CS + x1 * SN;
                                wy[1] = y2 * CS + x2 * SN;
                                wy[2] = wy[0];
                                wy[3] = wy[1];
                                S[s].d += dist(0, 0, (wx[0]+wx[1]) / 2, (wy[0]+wy[1]) / 2);
                                wz[0] = S[s].z1 - P.z+((P.i * wy[0])/32.0);
                                wz[1] = S[s].z1 - P.z+((P.i * wy[1])/32.0);
                                wz[2] = wz[0] + S[s].z2;
                                wz[3] = wz[1] + S[s].z2;

                                if(wy[0] < 1 && wy[1] < 1) continue;
                                if(wy[0] < 1){
                                        clip_behind(&wx[0], &wy[0], &wz[0], wx[1], wy[1], wz[1]);
                                        clip_behind(&wx[2], &wy[2], &wz[2], wx[3], wy[3], wz[3]);
                                }
                                if(wy[1] < 1){
                                        clip_behind(&wx[1], &wy[1], &wz[1], wx[0], wy[0], wz[0]);
                                        clip_behind(&wx[3], &wy[3], &wz[3], wx[2], wy[2], wz[2]);
                                }
                                wx[0] = wx[0] * 200 / wy[0] + W2; wy[0] = wz[0] * 200 / wy[0] + H2;
                                wx[1] = wx[1] * 200 / wy[1] + W2; wy[1] = wz[1] * 200 / wy[1] + H2;
                                wx[2] = wx[2] * 200 / wy[2] + W2; wy[2] = wz[2] * 200 / wy[2] + H2;
                                wx[3] = wx[3] * 200 / wy[3] + W2; wy[3] = wz[3] * 200 / wy[3] + H2;


                                draw_wall(wx[0], wx[1], wy[0], wy[1], wy[2], wy[3], get_color(W[w].c), s);
                        }
                        S[s].d /= (S[s].we - S[s].ws);
                        S[s].surface *= -1;
                }
        }

}