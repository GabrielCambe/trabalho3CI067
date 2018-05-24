#include "lista.h"

int insereInicio(tipoitem x, tipolista *lista){
  tipono *novo;
  
  MALLOC(novo, 1, tipono);
  novo->item = x;
  novo->prox = lista->inicio;
  lista->inicio = novo;
  
  return int;
}
