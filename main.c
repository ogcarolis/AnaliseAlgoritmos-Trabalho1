#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h> // Para srand e rand

#define MAX 2005 // Tamanho máximo do vetor de entrada

int n; // Quantidade de elementos
int arr[MAX]; // Vetor de entrada
int dp[MAX]; // Vetor auxiliar para programação dinâmica

// Função de comparação para qsort
int cmp(const void *a, const void *b) {
    int x = *(int *)a;
    int y = *(int *)b;
    return x - y; // Ordenação crescente simples
}

// ----------------------------
// Recursiva Pura
// ----------------------------
int RecursivoPuro(int idx) {
    int maxClique = 1; // Todo número sozinho forma um clique de tamanho 1
    for (int prev = 0; prev < idx; prev++) {
        if (arr[idx] % arr[prev] == 0) { // Verifica divisibilidade
            int cliqueSize = RecursivoPuro(prev) + 1;
            if (cliqueSize > maxClique) {
                maxClique = cliqueSize;
            }
        }
    }
    return maxClique;
}

// ----------------------------
// Top-Down com Memoization
// ----------------------------
int memo[MAX]; // Vetor para armazenar resultados já calculados
int TopDown(int idx) {
    if (memo[idx] != -1) return memo[idx];

    int maxClique = 1;
    for (int prev = 0; prev < idx; prev++) {
        if (arr[idx] % arr[prev] == 0) {
            int cliqueSize = TopDown(prev) + 1;
            if (cliqueSize > maxClique) {
                maxClique = cliqueSize;
            }
        }
    }
    memo[idx] = maxClique;
    return maxClique;
}

// ----------------------------
// Bottom-Up com Tabulation
// ----------------------------
// dp[i] armazena o tamanho do maior clique terminando em arr[i].
int BottomUp() {
    for (int i = 0; i < n; i++) {
        dp[i] = 1; // Cada elemento sozinho é um clique de tamanho 1
        for (int j = 0; j < i; j++) {
            if (arr[i] % arr[j] == 0) {
                if (dp[i] < dp[j] + 1) {
                    dp[i] = dp[j] + 1;
                }
            }
        }
    }

    int maxClique = 0;
    for (int i = 0; i < n; i++) {
        if (dp[i] > maxClique) maxClique = dp[i];
    }
    return maxClique;
}

// ----------------------------
// Função Principal
// ----------------------------
int main() {
    if (scanf("%d", &n) != 1) {
        fprintf(stderr, "Erro ao ler a quantidade de elementos.\n");
        return 1;
    }

    for (int i = 0; i < n; i++) {
        if (scanf("%d", &arr[i]) != 1) {
            fprintf(stderr, "Erro ao ler elemento %d.\n", i);
            return 1;
        }
    }

    // Ordena os números para garantir divisibilidade crescente
    qsort(arr, n, sizeof(int), cmp);

    printf("Elementos gerados:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    printf("=== Recursiva Pura ===\n");
    if (n <= 15) { // Limite prático para recursão pura
        int result = 0;
        for (int i = 0; i < n; i++) {
            int res = RecursivoPuro(i);
            if (res > result) result = res;
        }
        printf("Maior clique: %d\n", result);
    } else {
        printf("N muito grande para recursiva pura.\n");
    }

    printf("\n=== Top-Down com Memoization ===\n");
    memset(memo, -1, sizeof(memo)); // Inicializa o vetor de memoização
    int resultTD = 0;
    for (int i = 0; i < n; i++) {
        int res = TopDown(i);
        if (res > resultTD) resultTD = res;
    }
    printf("Maior clique: %d\n", resultTD);

    printf("\n=== Bottom-Up com Tabulation ===\n");
    int resultBU = BottomUp();
    printf("Maior clique: %d\n", resultBU);

    return 0;
}
