// lista.h
#ifndef __LISTA_H
#define __LISTA_H

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MALLOC(nome, tamanho, tipo) nome = (tipo*) malloc(tamanho * sizeof(tipo)); if(nome == NULL) abort()
#define FREE(nome) if(nome != NULL) free(nome)
#define ORDENA "-o"
#define REMOVE "-r"

typedef struct  {
  int chave;
} tipoitem;

typedef struct tipono {
  tipoitem item;
  struct tipono * prox;
}tipono;

typedef struct tipono * apontador;

typedef struct {
  apontador inicio;
  apontador fim;
} tipolista;

void iniciaLista(tipolista * lista);
int ehVazia(tipolista lista);

#endif
