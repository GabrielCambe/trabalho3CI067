// lista.h
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MALLOC(nome, tamanho, tipo) nome = (tipo*) malloc(tamanho * sizeof(tipo)); if(nome == NULL) abort()
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

void inicia(tipolista * lista);
int vazia (tipolista lista);

static int MULT;
static char *ARQUIVO1, *ARQUIVO2;
