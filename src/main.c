#include "controle.h"
#include "lista.h"


int main(int argc, char*argv[]){
  extern int i, num;
  extern int MULT;
  extern char *ARQUIVO1, *ARQUIVO2;
  extern int ORDEN ;
  extern int REMOVE0;

  
  init(); //declara as varáveis e as inicializa
  
  
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
	    printf("-r parametro: %d\n", MULT);
	    i += 2;
	    continue;  
	    
	  }else{
	    printf("-r Não teve parametro, ordena zeros\n");
	    REMOVE0 = 1;
	    i++;
	    continue; 
	  }
	}
	
	printf("-r Não teve parametro, ordena zeros\n");
	REMOVE0 = 1;
	i++;
	continue;
      }
      
      /* TESTANDO SE é "-o" */
      if(strncmp(argv[i-1], ORDENA, 2) == 0){
	ORDEN  = 1;
	printf("-o\n");
	i++;
	continue;
      }

      /* TESTANDO SE O ARGUMENTO É O NOME DO ARQUIVO1 */
      if(ARQUIVO1 == NULL){
	ARQUIVO1 = (char*) malloc(sizeof(argv[i-1])); if(ARQUIVO1 == NULL) abort();
	strcpy(ARQUIVO1, argv[i-1]);
	printf("%s\n", ARQUIVO1);
	i++;
	continue;

      /* TESTANDO SE O ARGUMENTO É O NOME DO ARQUIVO2 */
      }else{
	ARQUIVO2 = (char*) malloc(sizeof(argv[i])); if(ARQUIVO2 == NULL) abort();
	strcpy(ARQUIVO2, argv[i-1]);
	printf("%s\n", ARQUIVO2);
	i++;
	continue;	
      }
    }//while
    
    
  }else{
      printf("Número errado de argumentos!\n");   
  }
  
  ///////////////////////////////////
  for( i = 1; i <= argc-1; i++){
    printf(" %s", argv[i]);
  }
  printf("\n");
  ///////////////////////////////////

  FREE(ARQUIVO1);
  FREE(ARQUIVO2);
  return MULT;
}
