#include "controllersound.h"

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

byte catch_note(void)
{
    auto byte value;
    switch(SBUF)
    {
        case 'q':
            value = 1;  //template
        break;
        default:
            value = 0;
    }
    return value;
}

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

}

void read_keyboard(void) interrupt N //N = 0
{
    keyboard_call = true;
    return;
}