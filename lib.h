#include <at89x52.h>
#include <math.h>
//#include <stdbool.h>

//#include "debug.h"

#ifdef OUTSIDE_KEIL
#define bit int
#define interrupt
#define N
#endif

#define byte char
#define bool int
#define false 0
#define true 1

#define PI 3.14159

#define LCD P2
#define EN P3_6
#define RS P3_7