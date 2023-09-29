# alocacao-dinamica-de-mamoria

## Em C, você pode alocar memória dinamicamente usando as funções malloc para alocar memória para um vetor (array unidimensional) e malloc ou calloc para alocar memória para uma matriz (array bidimensional). Aqui estão exemplos de como fazer isso:

### Alocação de Memória para um Vetor (Array Unidimensional):

```c
#include <stdio.h>
#include <stdlib.h>

int main() {
    int tamanho;

    printf("Digite o tamanho do vetor: ");
    scanf("%d", &tamanho);

    // Aloca memória para o vetor de inteiros
    int *vetor = (int *)malloc(tamanho * sizeof(int));

    if (vetor == NULL) {
        printf("Falha na alocação de memória.\n");
        return 1;
    }

    // Agora você pode usar o vetor alocado dinamicamente
    for (int i = 0; i < tamanho; i++) {
        vetor[i] = i * 2;
    }

    // Libere a memória alocada quando não precisar mais dela
    free(vetor);

    return 0;
}
```
### Alocação de Memória para uma Matriz (Array Bidimensional):

```c
#include <stdio.h>
#include <stdlib.h>

int main() {
    int linhas, colunas;

    printf("Digite o número de linhas da matriz: ");
    scanf("%d", &linhas);
    printf("Digite o número de colunas da matriz: ");
    scanf("%d", &colunas);

    // Aloca memória para a matriz de inteiros
    int **matriz = (int **)malloc(linhas * sizeof(int *));

    if (matriz == NULL) {
        printf("Falha na alocação de memória para as linhas da matriz.\n");
        return 1;
    }

    for (int i = 0; i < linhas; i++) {
        matriz[i] = (int *)malloc(colunas * sizeof(int));
        if (matriz[i] == NULL) {
            printf("Falha na alocação de memória para as colunas da matriz.\n");
            return 1;
        }
    }

    // Agora você pode usar a matriz alocada dinamicamente
    for (int i = 0; i < linhas; i++) {
        for (int j = 0; j < colunas; j++) {
            matriz[i][j] = i + j;
        }
    }

    // Libere a memória alocada quando não precisar mais dela
    for (int i = 0; i < linhas; i++) {
        free(matriz[i]);
    }
    free(matriz);

    return 0;
}
```
### Lembre-se de que, após a alocação dinâmica de memória, é importante liberar essa memória usando free para evitar vazamentos de memória quando você não precisar mais dos arrays alocados dinamicamente.
