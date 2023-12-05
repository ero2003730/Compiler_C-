CC=gcc
CFLAGS=-I./src/h
BISON_FILES=./src/bison/bison.y
C_FILES=./src/c/main.c ./src/c/funcsLexical.c ./src/c/funcsSintatical.c ./src/c/funcsTabela.c ./src/c/regras.c
OUTPUT=program

all: bison compile

bison:
	bison -d $(BISON_FILES) -o ./src/c/bison.tab.c

compile: bison
	$(CC) $(CFLAGS) -o $(OUTPUT) $(C_FILES) ./src/c/bison.tab.c

run: compile
	./$(OUTPUT) ./src/teste/teste.txt

run_valgrind: compile
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./$(OUTPUT) ./src/teste/teste.txt

teste1: compile
	./$(OUTPUT) ./src/teste/teste.txt

teste2: compile
	./$(OUTPUT) ./src/teste/teste2.txt

clean:
	rm -f $(OUTPUT) ./src/c/bison.tab.c ./src/c/bison.tab.h

.PHONY: all bison compile run run_valgrind clean teste1 teste2
