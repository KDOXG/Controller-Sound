#include "lib.h"

void delay_ms(const int delay_ms)
{
    if (delay_ms < 1) return;

    //Periodo de 1.085069 microsegundos
    //50 ms / periodo = 922
    const unsigned short periods = 0xFFFF - 922;
    auto signed int repeat = delay_ms;
    auto unsigned byte timer_l, timer_h;
    
    timer_l = periods;
    timer_h = periods >> 8;

    //Configurando o timer no modo 1
    TMOD = 0x01;

    do
    {
        //Passa parte baixa e parte alta para os registradores do timer
        TL0 = timer_l;
        TH0 = timer_h;

        TR0 = 1;                    //Liga o timer

        while(1) if (TF0) break;          //Espera o timer chegar em 0
        
        TR0 = 0;                    //Desliga o timer
        TF0 = 0;                    //Limpa a flag de interrupção

        repeat--;                  //Decrementa o valor de repeticoes
    } while (repeat);

    //Desconfigurando o timer
    TMOD = 0;
    
    return;
}

void init_input_output(void)
{

}

void init_lcd(void)
{

}

void write_lcd(void)
{

}

void disable_int_global(void)
{

}

void enable_int_global(void)
{

}
