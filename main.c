#include "controllersound.h"

void main(void)
{
    auto bool square_mode = true;
    auto bool triangle_mode = false;
    auto bool use_tremolo = false;
    auto bool use_vibrato = false;
    keyboard_call = false;

    auto byte sound;

    init_inout();
    init_lcd();
    enable_int_global();

    while(1)
    {

    do
    {
        RI = 0;
        while(1)
        {
            if (RI) break;

            if (keyboard_call)
            {
                IE0 = 0;
                disable_int_global();
                //while (1)
                {
                    //call SETCHAR_H
                    //if (input_keyboard == EXIT) break;
                    //switch case with input_keyboard
                    write_lcd();
                }
                keyboard_call = false;
                enable_int_global();
            }
        }

    }
    while(is_not_input());

    sound = catch_note();

    }
    return;
}