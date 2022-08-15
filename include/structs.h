/**
 * @brief home to all SDL and screen variables
 * 
 */
typedef struct {
        SDL_Renderer *ren;
        SDL_Texture  *tex;
        SDL_Window   *win;
        unsigned int *pix;

        const Uint8 *inkeys;
} Game;

/**
 * @brief this is the angle look up table to avoid cos and sin in loops
 * 
 */
typedef struct {
        float cos[MA];
        float sin[MA];
} Angles;

/**
 * @brief  player information
 * 
 */
typedef struct {
        int x, y, z;
        int a, i;
        int j;
        int acc;
} Player;

typedef struct {
        int x1, y1;
        int x2, y2;
        int c;
} Walls;

typedef struct {
        int ws, we;
        int z1, z2;
        int d;
        int c1, c2;
        int surf[SW];
        int surface;
} Sectors;