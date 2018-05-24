#ifndef __CONTROLE_H
#define __CONTROLE_H

#include <string.h>

extern int i, num;
extern int MULT;
extern char *ARQUIVO1, *ARQUIVO2;
extern int ORDEN ;
extern int REMOVE0;

int isnum(const char *str);

inline void init(){
  extern int num;
  extern int MULT;
  extern char *ARQUIVO1, *ARQUIVO2;
  extern int ORDEN ;
  extern int REMOVE0;

  num = 1;
  REMOVE0=0;
  ORDEN  = 0;
  MULT = 0;
  ARQUIVO1 = NULL; ARQUIVO2 = NULL;
  
}



#endif
