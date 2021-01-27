#include "print.h"
#include "core.h"

#include <stdio.h>

char version = 0.01;
char ram;

//main functions:

void kernel_main(){
    print_clear();
    print_set_color(PRINT_COLOR_RED, PRINT_COLOR_BLACK);
    print_str("Welcome To Blue OS with 64-bit kernel! "+ version );
}
//Ram functions:

void checkRAM(){

}
