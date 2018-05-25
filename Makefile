NOME = -o montalista
MAIN_src = main.c

LIBS_dep = liblista.so
LIBS = ./libs/
SRC = ./src/
INCLUDE = ./include/
INCLUDE_o = $(INCLUDE)obj/
LISTo_src = $(SRC)iniciaLista.c $(SRC)ehVazia.c

MAIN_dep = lista.o $(LIBS_dep)
MAIN_o = $(INCLUDE_o)lista.o

LIB_src = $(SRC)insereInicio.c $(SRC)insereFim.c
LIB_o = $(LIB_src:.c=.o)

CC = gcc
CC_flags = -Wall -I$(INCLUDE) -L$(LIBS) -llista



all: montalista

montalista: $(MAIN_dep)
	@echo "Compilando \"montalista\"..."
	@echo $(CC) $(NOME) $(MAIN_o) $(SRC)$(MAIN_src) $(CC_flags)
	@echo "Pronto."

lista.o:
	@echo "Compilando as funções de \"lista.h\"..."
	@$(CC) -c $(LISTo_src) $(CC_flags)
	@echo "Criando \"lista.o\"..."
	@ld -r *.o -o $(INCLUDE_o)lista.o
	@rm *.o

liblista.so:
	@echo $(CC) -fPIC -c $(LIBS_src)
	@echo $(CC) -shared -o $(LIBS)liblista.so $(LIB_o) 

debug: cc_debug gdb

cc_debug: $(MAIN_dep)
	@echo "Compilando \"montalista\" para DEBUG..."
	@$(CC) $(NOME) $(MAIN_o) $(SRC)$(MAIN_src)  $(CC_flags) -g
	@echo "Pronto."

gdb:
	@echo
	@echo "Invocando o GDB,,,"
	@gdb -q montalista

cleano:
	@echo "Removendo os arquivo-objetos em $(INCLUDE_o)..."
	@rm $(INCLUDE_o)*.o
	@echo "Pronto."

purge:
	@echo "Removendo \"montalista\"..."
	@rm montalista
	@echo "Pronto."


#regras para o controle de versão
commit:
	git update-index
	git commit -m "commit com MAKE"
	git push

update:
	git update-index --add
	git commit -a --dry-run
	git add --all

lbranch:
	@git branch --list -a

cbranch:
	@git checkout -b porDepurar --track
