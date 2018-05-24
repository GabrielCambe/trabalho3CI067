#include "lista.h"

int main(int argc, char*argv[]){
  int i;
  int MULT;
  char *ARQUIVO1, *ARQUIVO2;

  MULT = 0;
  ARQUIVO1 = NULL; ARQUIVO2 = NULL;
  
  printf("%s ", argv[0]); ////

  /* TESTANDO SE TENHO UM NÚMERO CERTO DE ARGUMENTOS */
  if((argc >= 1) && (argc <= 5)){
    i = 2;
    /* WHILE PARA INTERPRETAR OS ARGUMENTOS */
    while(i <= argc){
      /* TESTANDO SE é "-o" */
      if(strcmp(argv[i-1], ORDENA) == 0){
        i++;
	continue;
      }
      
      /* TESTANDO SE é "-r" */
      if(strcmp(argv[i-1], REMOVE) == 0){
        //TESTANDO O PROXIMO ARGUMENTO
	if(argc >= i+1){
	  if(isdigit( argv[i])){
	    MULT = atoi(argv[i]);
	    i += 2;
	    continue;
	    
	  }
	  
	}else{
	  printf("O argumento \"-r\" necescita de um parâmetro!\n");
    
	  FREE(ARQUIVO1);
	  FREE(ARQUIVO2);
	  return 0;
	  
	}
	i++;
	continue;
      }

      /* TESTANDO SE O ARGUMENTO É O NOME DO ARQUIVO1 */
      if(ARQUIVO1 == NULL){
	ARQUIVO1 = (char*) malloc(sizeof(argv[i-1])); if(ARQUIVO1 == NULL) abort();

	strcpy(ARQUIVO1, argv[i-1]);
	i++;
	continue;

      /* TESTANDO SE O ARGUMENTO É O NOME DO ARQUIVO2 */
      }else{
	ARQUIVO2 = (char*) malloc(sizeof(argv[i])); if(ARQUIVO2 == NULL) abort();
	
	strcpy(ARQUIVO2, argv[i-1]);
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
