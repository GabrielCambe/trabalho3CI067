#include "liblista.h"

void imprime(tipolista lista, FILE *arqsaida){
  //arqsaida = fopen(ARQUIVO1, "w+");
  apontador i;
  if(arqsaida == NULL){
    for(i = lista.inicio; i != NULL; i = i->prox){
      printf("%d ", i->item.chave);
    }
    printf("\n");
  }else{
    for(i = lista.inicio; i != NULL; i = i->prox){
      fprintf(arqsaida, "%d ", i->item.chave);
    }
    fprintf(arqsaida, "\n");
  }

  return;
}
