#include "controllersound.h"

volatile int note;

volatile float note_value;

volatile float i;

volatile bool square_wave;

void ISR_SERIAL(void) interrupt 4
{
    return;
}

bool is_not_input(void)
{
    switch(SBUF)
    {
        case 'q':
        case 'w':
        case 'e':
        case 'r':
        case 't':
        case 'y':
        case 'u':
        case 'i':
        case 'o':
        case 'p':
        case 'Q':
        case 'W':
        case 'E':
        case 'R':
        case 'T':
        case 'Y':
        case 'U':
        case 'I':
        case 'O':
        case 'P':
            return false;
    }
    return true;
}

float catch_note(void)
{
    auto byte value;
    switch(SBUF)
    {
        case 'q':               //C2
        case 'Q':
            value = 65.40639;
        case 'w':               //D2
        case 'W':
            value = 73.41619;
        case 'e':               //E2
        case 'E':
            value = 82.40689;
        case 'r':               //F2
        case 'R':
            value = 87.30706;
        case 't':               //G2
        case 'T':
            value = 97.99886;
        case 'y':               //A2
        case 'Y':
            value = 110.0000;
        case 'u':               //B2
        case 'U':
            value = 123.4708;
        case 'i':               //C3
        case 'I':
            value = 130.8128;
        case 'o':               //D3
        case 'O':
            value = 146.8324;
        case 'p':               //E3
        case 'P':
            value = 164.8138;
        break;
        default:
            value = 0;
    }
    return value;
}

void init_int(void)
{
    IE = 0x90;
	TH1 = 0xFD;
	TL1 = 0XFD;
	TR1 = 1;
}

void enable_int_global(void)
{
    IE = 0x90;
}

void disable_int_global(void)
{
    IE = 0x00;
}

void main(void)
{
    /*
    square_mode = true;
    triangle_mode = false;
    use_tremolo = false;
    use_vibrato = false;
    keyboard_call = false;
    */
    P0 = 0;

    //init_lcd();
    enable_int_global();

    square_wave = 1;

    while(1)
    {

    do
    {
        RI = 0;
        while(1)
        {
            if (RI) break;
        }
    }
    while(is_not_input());

    disable_int_global();

    for (i = 0; i < 100; i++)
    {
        note_value = catch_note();

        if (square_wave)
        {
            note_value *= i;
            note_value *= 2*PI;
            note_value = sin(note_value);
            note_value = note_value >= 0 ? 1 : 0;
        }

        note_value *= 255;
        P0 = (int) i;
    }

    enable_int_global();

    }
    return;
}