#include "m_utils.h"

int
dist(int x1, int y1, int x2, int y2)
{
        int dist = sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
        return dist;
}