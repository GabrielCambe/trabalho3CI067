NOME = -o montalista
MAIN_src = main.c
SRC = ./src/
INCLUDE = ./include/

CC = gcc
CC_flags = -Wall -I$(INCLUDE)



all: montalista

montalista:
	@echo "Compilando montalista..."
	@$(CC) $(NOME) $(SRC)$(MAIN_src) $(CC_flags)
	@echo "Pronto..."

debug: cc_debug gdb

cc_debug:
	@echo "Compilando montalista para DEBUG..."
	@$(CC) $(NOME) $(SRC)$(MAIN_src) $(CC_flags) -g
	@echo "Pronto..."

gdb:
	gdb montalista

purge:
	@rm montalista

#regras para o controle de versão
commit:
	git update-index
	git commit -m "commit com MAKE"
	git push

update:
	git update-index --add
	git commit -a --dry-run
	git add --all
