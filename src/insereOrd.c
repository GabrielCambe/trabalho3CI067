#include "lista.h"

int insereFim(tipoitem x, tipolista *lista){
  tipono *novo; apontador i;

  MALLOC(novo, 1, tipono);
  novo->item = x;

  for(i = lista.inicio; i != NULL; i = i.prox){
    if(i->)
  }
  
  novo->prox = NULL;
  lista->fim->prox = novo;
  lista->fim = novo;

  return 1;
}
