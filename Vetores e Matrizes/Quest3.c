#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int n;
    printf("Digite a ordem da matriz quadrada: ");
    scanf("%d", &n);

    // Aloca a matriz quadrada
    int **matriz = (int **)malloc(n * sizeof(int *));
    if (matriz == NULL)
    {
        printf("Erro de alocação!\n");
        return 1;
    }
    for (int i = 0; i < n; i++)
    {
        matriz[i] = (int *)malloc(n * sizeof(int));
        if (matriz[i] == NULL)
        {
            for (int j = 0; j < i; j++)
                free(matriz[j]);
            free(matriz);
            return 1;
        }
    }

    // Inicializa o gerador de números aleatórios
    srand(time(NULL));

    // Preenche com números entre 1 e 100
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            matriz[i][j] = rand() % 100 + 1;
        }
    }

    // Exibe a matriz
    printf("Matriz %dx%d com números aleatórios:\n", n, n);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%3d ", matriz[i][j]);
        }
        printf("\n");
    }

    // Libera a memória
    for (int i = 0; i < n; i++)
        free(matriz[i]);
    free(matriz);

    return 0;
}