#include "lib.h"

volatile bool keyboard_call;

bool is_not_input(void);

byte catch_note(void);

byte tremolo(byte);

byte vibrato(byte);

void read_serial(void) interrupt N; //N = 4

void read_matrixkeyboard(void) interrupt N; //N = 0