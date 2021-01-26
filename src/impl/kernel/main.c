#include "print.h"
//}
void _putchar(char c, int *column) {//input functions not woking
    char *start;
    start = (char *)0xb8000;
    char *loc;
    loc = start + ((*column) * 2);
    *loc = c;
    *column += 1;
}

#include <stdio.h>

//main functions:

void kernel_main(){
    print_clear();
    print_set_color(PRINT_COLOR_RED, PRINT_COLOR_BLACK);
    print_str("Welcome To Blue OS with 64-bit kernel!");
}


