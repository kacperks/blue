#include "print.h"

typedef int bool;
#define true 1
#define false 0

#include <stdio.h>

char* newline = "\n\r";
char* version = "0.0.1 PRE-ALPHA";

//main functions:

void kernel_main(){
    print_clear();
    print_set_color(PRINT_COLOR_RED, PRINT_COLOR_BLACK);
    print_str("Welcome To Blue OS with 64-bit kernel!");
}


