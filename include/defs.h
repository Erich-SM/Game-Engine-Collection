#define R       4
#define PR      2
#define SW       240
#define W2      (SW/2) 
#define SH       220
#define H2      (SH/2)
#define T       0
#define MA      360 // max angles for viewing
#define NW       28
#define NS       5
#define TXH     64
#define TXW     64

#define GRAV    0.1

#define min(a,b) (((a) < (b)) ? (a) : (b)) // min: Choose smaller of two values.
#define max(a,b) (((a) > (b)) ? (a) : (b)) // max: Choose bigger of two values.
#define clamp(a, mi,ma) min(max(a,mi),ma)  // clamp: Clamp value into set range.