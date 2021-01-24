#include "print.h"

typedef int bool;
#define true 1
#define false 0

#include <stdio.h>

const char* input();
void execute(const char* cmd);
void output(const char* s, bool ln);
void _puts(const char* s);
void _putchar(char c,int column);

char* newline = "\n\r";
char* version = "0.0.1 PRE-ALPHA";

void kernel_main(){
    print_clear();
    print_set_color(PRINT_COLOR_RED, PRINT_COLOR_BLACK);
    print_str("Welcome To Blue OS with 64-bit kernel!");
    output("Type 'help' for a list of commands.",1);
    output("",1);
    while(1==1) {
        output("> ",0);
        execute(input());
        output("",1);
    }
}
void execute(const char* cmd) {
    output(cmd,1);
}

const char* input() {
    char inpt[2] = {0,0};
    scanf("%c",inpt);
    return inpt;
}

void output(const char* s, bool ln) {
    _puts(s);
    if (ln==1) {
        _puts(newline);
    }
}

void _puts(const char* s) {
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
void _putchar(char c, int *column) {
    char *start;
    start = (char *)0xb8000;
    char *loc;
    loc = start + ((*column) * 2); //Two bytes per cell: one for the char, other for color
    *loc = c;
    *column += 1;
}
