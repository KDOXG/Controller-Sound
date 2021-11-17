//#include "controllersound.h"
#include "lib.h"

volatile bool keyboard_call;

volatile bool square_mode;

volatile bool triangle_mode;

volatile bool use_tremolo;

volatile bool use_vibrato;

bool is_not_input(void);

byte catch_note(void);

byte tremolo(byte);

byte vibrato(byte);

void read_serial(void) interrupt N; //N = 4

void read_matrixkeyboard(void) interrupt N; //N = 0

byte tremolo(const byte note)
{
    return 0;
}

byte vibrato(const byte note)
{
    return 0;
}

void read_serial(void) interrupt N //N = 4
{
    return;
}

void read_matrixkeyboard(void) interrupt N //N = 0
{
    keyboard_call = true;
    return;
}