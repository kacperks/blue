#include <stdio.h>

typedef int bool;
#define true 1
#define false 0

#include <stdio.h>

char* newline = "\n\r";
char* version = "0.0.1 PRE-ALPHA";

class input{
public :
  const char* input();
  void execute(const char* cmd);
  void output(const char* s, bool ln);
  void _puts(const char* s);
  void _putchar(char c,int column);
  }
