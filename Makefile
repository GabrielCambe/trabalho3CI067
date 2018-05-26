


all: install-paths montalista

install-paths:
	./install-paths.sh

montalista: liblista.so lista.o
	@echo "Compilando \"montalista\"..."
	@gcc -o montalista -I./include/ -L./libs/ ./include/obj/lista.o ./src/main.c -llista -Wall
	@echo "Pronto."

lista.o:
	@echo "Compilando as funções de \"lista.h\"..."
	@gcc -c -I./include/ ./src/iniciaLista.c ./src/ehVazia.c -Wall 
	@echo "Criando \"lista.o\"..."
	@ld -r *.o -o ./include/obj/lista.o
	@rm *.o
	@echo "Pronto."

liblista.so:
	@echo "Compilando as funções de \"liblista.so\"..."
	@gcc -fPIC -c -I./include/ ./src/insereInicio.c ./src/imprime.c ./src/insereFim.c -Wall
	@mv *.o ./src/
	@echo "Criando \"liblista.so\"..."
	@gcc -o ./libs/liblista.so -shared -I./include/ ./src/insereInicio.o ./src/imprime.o ./src/insereFim.o -Wall
	@rm ./src/*.o
	@echo "Pronto."

debug: cc_debug gdb

cc_debug: lista.o liblista.so
	@echo "Compilando \"montalista\" para DEBUG..."
	@gcc -o montalista ./include/obj/lista.o ./src/main.c -Wall -I./include/ -L./libs/ -llista -g
	@echo "Pronto."

gdb:
	@echo
	@echo "Invocando o GDB..."
	@gdb -q montalista

distclean: cleano purge

cleano:
	@echo "Removendo os arquivo-objetos em \"./include/obj/\"..."
	@rm ./include/obj/*.o
	echo "Removendo as bibliotecas em \"./libs/liblista.so\" ..."
	@rm ./libs/liblista.so
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
	git branch --list -a

cbranch:
	git checkout -b porDepurar --track
