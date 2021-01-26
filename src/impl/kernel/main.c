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


//input functions : 

void execute(const char* cmd) {//input functions not woking
    output(cmd,1);
}

const char* input() {//input functions not woking
    char inpt[2] = {0,0};
    scanf("%c",inpt);
    return inpt;
}

void output(const char* s, bool ln) {//input functions not woking
    _puts(s);
    if (ln==1) {
        _puts(newline);
    }
}

void _puts(const char* s) {//input functions not woking
    while(*s != 0) {
        _putchar(*s, *s);
        s++;
    }
}

//void _putchar(char c) {
  //  __asm {
  //      mov ah, 0Eh
  //      mov al, [c]
  //      mov bh, 0
  //      mov bl, 0Fh
  //      int 10h
    //}
//}
void _putchar(char c, int *column) {//input functions not woking
    char *start;
    start = (char *)0xb8000;
    char *loc;
    loc = start + ((*column) * 2);
    *loc = c;
    *column += 1;
}
