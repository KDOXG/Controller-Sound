#include <at89x52.h>
#include <stdbool.h>

#include "debug.h"

#ifdef OUTSIDE_KEIL
#define bit int
#define interrupt
#define N
#endif

#define byte unsigned char

#define LCD P2
#define EN P3_6
#define RS P3_7

void delay_ms(int);

void init_input_output(void);

void init_lcd(void);

void write_lcd(void);

void disable_int_global(void);

void enable_int_global(void);