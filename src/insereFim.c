#include "liblista.h"

int insereFim(tipoitem x, tipolista *lista){
  tipono *novo;

  MALLOC(novo, 1, tipono);
  novo->item = x;
  novo->prox = NULL;
  lista->fim->prox = novo;
  lista->fim = novo;

  return 1;
}
