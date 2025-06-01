# Compila main.c para gerar o executável 'main'
CC=gcc
CFLAGS=-Wall -O2 -Werror=unused-result

all: main

main: main.c
	$(CC) $(CFLAGS) -o main main.c

# Testes com diferentes tamanhos de entrada
test-small:
	@echo "Testando com entrada pequena (n=10)"
	@echo "10" | ./main

test-medium:
	@echo "Testando com entrada média (n=100)"
	@echo "100" | ./main

test-large:
	@echo "Testando com entrada grande (n=1000)"
	@echo "1000" | ./main

test: test-small test-medium test-large

.PHONY: all clean test test-small test-medium test-large

clean:
	rm -f main
