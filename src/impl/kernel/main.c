#include "print.h"

#include <stdio.h>

//main functions:

void kernel_main(){
    print_clear();
    print_set_color(PRINT_COLOR_RED, PRINT_COLOR_BLACK);
    print_str("Welcome To Blue OS with 64-bit kernel!");
}


