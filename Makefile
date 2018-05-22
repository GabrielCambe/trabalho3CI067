NOME = -o montalista
MAIN_src = main.c
SRC = ./src/
INCLUDE = ./include/

CC = gcc
CC_flags = -Wall -I$(INCLUDE)


all: montalista 

montalista:
	$(CC) $(NOME) $(SRC)$(MAIN_src) $(CC_flags) -I$(INCLUDE)

purge:
	rm montalista

#regras para o controle de versão
commit:
	git update-index
	git commit -m "commit com MAKE"
	git push

update:
	git update-index --add
	git commit -a --dry-run
	git add --all
