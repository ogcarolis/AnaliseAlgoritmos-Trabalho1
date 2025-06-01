# CS Academy: Divisor Clique
Trabalho 1 da matéria de Análise de Algoritmos. O problema de Programação Dinâmica utilizado é o [Divisor Clique](https://csacademy.com/contest/archive/task/divisor_clique/statement/) da CS Academy.

# Análise de Algoritmos - Trabalho 1

Este projeto resolve o problema de encontrar o maior subconjunto (clique) de números em que cada elemento é divisível por todos os anteriores do subconjunto. O código implementa três abordagens para resolver o problema:

## Métodos Implementados

- **Recursiva Pura:**  
  Calcula o maior clique de forma recursiva, sem otimizações. Só é viável para pequenas entradas (n ≤ 15).

- **Top-Down com Memoization:**  
  Utiliza programação dinâmica com memoização para evitar recomputações, tornando a solução eficiente para valores maiores de n.

- **Bottom-Up com Tabulation:**  
  Implementação iterativa da programação dinâmica, preenchendo uma tabela de soluções parciais.

## Como Compilar

### Usando o Makefile

Se você possui o `make` instalado, basta executar:

```
make
```

Isso irá compilar o arquivo `main.c` e gerar o executável `main`.

Para a execução dos testes, basta executar:

```
make test
```

Para limpar os arquivos gerados:

```
make clean
```

### Compilação Manual

Se preferir compilar manualmente com o GCC:

```
gcc -Wall -O2 -o main main.c
```

## Como Executar

Após a compilação, execute o programa:

```
./main
```

O programa espera como entrada:
- Um número inteiro `n` (quantidade de elementos)

Exemplo de entrada:
```
5
```

## Observações

- O arquivo `.gitignore` está configurado para ignorar arquivos `.exe`.
