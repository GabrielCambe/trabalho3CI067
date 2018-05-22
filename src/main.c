#include "lista.h"

int main(int argc, char*argv[]){
  int i;
  
  printf("%s ", argv[0]); ////

  /* TESTANDO SE TENHO UM NÚMERO CERTO DE ARGUMENTOS */
  if((argc > 1) && (argc <= 5)){
    ARQUIVO1 = NULL; ARQUIVO2 = NULL;
    i = 1;
    /* WHILE PARA INTERPRETAR OS ARGUMENTOS */
    while(i < argc){
      /* TESTANDO SE é "-o" */
      if(strcmp(argv[i], ORDENA) == 0){
	printf("%s ", argv[i]); ////
	i++;
	continue;
      }

      /* TESTANDO SE é "-r" */
      if(strncmp(argv[i], REMOVE, 2) == 0){
	/* TESTANDO SE "-r" É DO TIPO "-rX" */
	if(argv[i][2] != '\0'){
	  MULT = atoi((const char *) argv[i][2]);
	  i++;
	  continue;

	//TESTANDO O PROXIMO ARGUMENTO
	}else if(argc >= i+1){
	  if(isdigit(argv[i+1])){
	    MULT = atoi(argv[i+1]);
	    i++;
	    continue;

	  }
	}else{
	  printf("O argumento \"-r\" necescita de um parâmetro!\n");
	  return 0;

	}
	printf("%s ", argv[i]); ////
	i++;
	continue;

      }

      /* TESTANDO SE O ARGUMENTO É O NOME DO ARQUIVO1 */
      if(ARQUIVO1 == NULL){
	ARQUIVO1 = (char*) malloc(sizeof(argv[i]));
	ARQUIVO1 = argv[i];
	i++;
	continue;
      /* TESTANDO SE O ARGUMENTO É O NOME DO ARQUIVO2 */
      }else{
	ARQUIVO2 = (char*) malloc(sizeof(argv[i]));
	ARQUIVO2 = argv[i];
	i++;
	continue;
	
      }
      
    }//while

    
  }else{
    printf("Número errado de argumentos!\n");   
  }
  return 0;
}
