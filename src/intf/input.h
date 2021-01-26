#include <stdio.h>

class input{
public :
  const char* input();
  void execute(const char* cmd);
  void output(const char* s, bool ln);
  void _puts(const char* s);
  void _putchar(char c,int column);
  }
