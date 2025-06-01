# Compila main.c para gerar o executável 'main'
CC=gcc
CFLAGS=-Wall -O2 -Werror=unused-result

all: main

main: main.c
	$(CC) $(CFLAGS) -o main main.c

test-1:
	@echo "=== Teste 1 ==="
	@echo "5" > input.txt
	@echo "8 32 12 16 4" >> input.txt
	@./main < input.txt

test-2:
	@echo "=== Teste 2 ==="
	@echo "8" > input.txt
	@echo "20 6 200 4 36 108 40 2" >> input.txt
	@./main < input.txt

test-3:
	@echo "=== Teste 3 ==="
	@echo "8" > input.txt
	@echo "108 4 360 6 756 18 2 36" >> input.txt
	@./main < input.txt

test: test-1 test-2 test-3
	@rm -f input.txt

.PHONY: all clean test test-1 test-2 test-3

clean:
	rm -f main input.txt
