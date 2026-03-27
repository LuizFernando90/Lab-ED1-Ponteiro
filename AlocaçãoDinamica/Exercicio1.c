#include <stdio.h>
#include <stdlib.h>

int main()
{
    int linhas = 5, colunas = 5;

    // 1. Aloca um vetor de ponteiros para as linhas
    int **matriz = (int **)malloc(linhas * sizeof(int *));
    if (matriz == NULL)
    {
        printf("Erro de alocação de memória!\n");
        return 1;
    }

    // 2. Para cada linha, aloca um vetor de inteiros (colunas)
    for (int i = 0; i < linhas; i++)
    {
        matriz[i] = (int *)malloc(colunas * sizeof(int));
        if (matriz[i] == NULL)
        {
            printf("Erro de alocação na linha %d\n", i);
            // Libera as linhas já alocadas antes de sair
            for (int j = 0; j < i; j++)
                free(matriz[j]);
            free(matriz);
            return 1;
        }
    }

    // 3. Preenche a matriz com os índices: matriz[i][j] = i*5 + j
    for (int i = 0; i < linhas; i++)
    {
        for (int j = 0; j < colunas; j++)
        {
            matriz[i][j] = i * 5 + j;
        }
    }

    // 4. Imprime a matriz
    printf("Matriz 5x5 preenchida:\n");
    for (int i = 0; i < linhas; i++)
    {
        for (int j = 0; j < colunas; j++)
        {
            printf("%3d ", matriz[i][j]);
        }
        printf("\n");
    }

    // 5. Libera a memória alocada
    for (int i = 0; i < linhas; i++)
    {
        free(matriz[i]); // libera cada linha
    }
    free(matriz); // libera o vetor de ponteiros

    return 0;
}