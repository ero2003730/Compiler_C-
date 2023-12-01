CC=gcc
CFLAGS=-I./src/h
BISON_FILES=./src/bison/bison.y
C_FILES=./src/c/main.c ./src/c/funcsLexical.c ./src/c/funcsSintatical.c
OUTPUT=program

all: bison compile run

bison:
	bison -d $(BISON_FILES) -o ./src/c/bison.tab.c

compile:
	$(CC) $(CFLAGS) -o $(OUTPUT) $(C_FILES) ./src/c/bison.tab.c

run:
	./$(OUTPUT) ./src/teste/teste.txt

run_valgrind:
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./$(OUTPUT) ./src/teste/teste.txt

clean:
	rm -f $(OUTPUT) ./src/c/bison.tab.c ./src/c/bison.tab.h

.PHONY: all bison compile run run_valgrind clean
