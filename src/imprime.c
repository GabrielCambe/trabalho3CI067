#include "lista.h"

void imprime(tipolista lista, FILE *arqsaida){
  //arqsaida = fopen(ARQUIVO1, "w+");
  apontador i;
  
  for(i = lista.inicio; i != NULL; i = i.prox){
    printf("%d ", i.item.chave);
  }
  printf("\n");

  return;
}
