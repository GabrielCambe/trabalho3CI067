#include "lista.h"

void imprime(tipolista lista, FILE *arqsaida){
  //arqsaida = fopen(ARQUIVO1, "w+");
  apontador i;
  
  for(i = lista.inicio; i != NULL; i = i.prox){
    fprintf(arqsaida , "%d ", i.item.chave);
  }
  fprintf(arqsaida, "\n");

  return;
}
