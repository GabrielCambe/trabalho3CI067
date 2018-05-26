#include "controle.h"
#include "lista.h"
#include "liblista.h"


int main(int argc, char*argv[]){
  int i, num;
  char *ARQUIVO1, *ARQUIVO2;
  extern int MULT;
  extern int ORDEN ;
  extern int REMOVE0;
  extern FILE *ARQ1, *ARQ2;
  tipolista LISTA;

  num = 1;
  REMOVE0=0;
  ORDEN  = 0;
  MULT = 0;
  ARQUIVO1 = NULL; ARQUIVO2 = NULL;  
  
  //ocessa_input(); //processa os argumentos passados pelo usuário

  
  /* TESTANDO SE TENHO UM NÚMERO CERTO DE ARGUMENTOS */
  if((argc > 1) && (argc <= 6)){
    i = 2;
    
    /* WHILE PARA INTERPRETAR OS ARGUMENTOS */
    while(i <= argc){
      /* TESTANDO SE é "-r" */
      if(strncmp(argv[i-1], REMOVE, 2) == 0){
        //TESTANDO O PROXIMO ARGUMENTO
	if((i+1) <= argc){
	  num = isnum(argv[i]);
	  if(num){
	    MULT = atoi(argv[i]);
	    i += 2;
	    continue;  
	    
	  }else{
	    REMOVE0 = 1;
	    i++;
	    continue; 
	  }
	}
	
        REMOVE0 = 1;
	i++;
	continue;
      }
      
      /* TESTANDO SE é "-o" */
      if(strncmp(argv[i-1], ORDENA, 2) == 0){
	ORDEN  = 1;
	i++;
	continue;
      }

      /* TESTANDO SE O ARGUMENTO É O NOME DO ARQUIVO1 */
      if(ARQUIVO1 == NULL){
	ARQUIVO1 = (char*) malloc(sizeof(argv[i-1])); if(ARQUIVO1 == NULL) abort();
	strcpy(ARQUIVO1, argv[i-1]);
	if((ARQ1 = fopen(ARQUIVO1, "r+")) == NULL){
	  printf("O arquivo de entrada não existe!\n");
	  break;
	}
	i++;
	continue;
	
       /* TESTANDO SE O ARGUMENTO É O NOME DO ARQUIVO2 */
      }else{
	if(ARQUIVO2 == NULL){
	  ARQUIVO2 = (char*) malloc(sizeof(argv[i])); if(ARQUIVO2 == NULL) abort();
	  strcpy(ARQUIVO2, argv[i-1]);
	  ARQ2 = fopen(ARQUIVO2, "w");
	  i++;
	  continue;

	}else{
	  printf("Argumentos passados incorretamente!\n");
	  break;
	}	
      }
    }//while
   
  }else{
      printf("Número errado de argumentos!\n");   
  }

  
  iniciaLista(&LISTA);
  //crialista();
  {
    int chave;
    
  /*INSERINDO OS ELEMENTOS NA LISTA*/
    while(!feof(ARQ1)){
      tipoitem *novo;
      fscanf(ARQ1, "%d", &chave);
      
      if(ehVazia(LISTA)){
	MALLOC(novo, 1, tipoitem);
	novo->chave = chave;
	if(insereInicio((*novo), &LISTA))
	  continue;
	
      }else{
	MALLOC(novo, 1, tipoitem);
	novo->chave = chave;
	if(insereFim((*novo), &LISTA))
	  continue;
	
      }
    }
  }
  


  apontador indx, indx_free;
  for(indx = LISTA.inicio; indx != NULL;){
    free(&(indx->item));
    indx_free = indx;
    indx = indx->prox;
    free(indx_free);
  }
  
  imprime(LISTA, ARQ2);
  
  FREE(ARQUIVO1);
  FREE(ARQUIVO2);
  return MULT;
}

/*
void crialista(){
int chave; apontador ptr;

  //INSERINDO OS ELEMENTOS NA LISTA
  while(!feof(ARQ1)){
    fscanf(ARQ1, "%d", &chave);
    
    
    if(ehVazia(LISTA)){
      MALLOC(LISTA.inicio, 1, tipono);
      LISTA.inicio->item.chave = chave;
      LISTA.inicio->prox = NULL;
      ptr = LISTA.inicio;
      LISTA.fim = ptr;

    }else{
      MALLOC(ptr->prox, 1, tipono);
      ptr->prox->item.chave = chave;
      ptr->prox->prox = NULL;
      ptr = ptr->prox;
      LISTA.fim = ptr;
      
    }
  }
} */
