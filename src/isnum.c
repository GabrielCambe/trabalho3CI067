#include "controle.h"

int isnum(const char *str){
  int i, flag;
  char c;
  i = 0;
  flag = 1;
  for(c = str[i]; c != '\0'; c = str[i++])
    if(isdigit(c) == 0)
      flag = 0;

  return flag;
}
