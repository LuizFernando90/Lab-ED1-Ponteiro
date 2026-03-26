#include <stdio.h>
#include <stdlib.h>

int main()
{
    int linhas, colunas;
    printf("Digite o número de linhas e colunas: ");
    scanf("%d %d", &linhas, &colunas);

    // Aloca um vetor de ponteiros (linhas)
    int **matriz = (int **)malloc(linhas * sizeof(int *));
    if (matriz == NULL)
    {
        printf("Erro de alocação!\n");
        return 1;
    }

    // Para cada linha, aloca um vetor de inteiros (colunas)
    for (int i = 0; i < linhas; i++)
    {
        matriz[i] = (int *)malloc(colunas * sizeof(int));
        if (matriz[i] == NULL)
        {
            printf("Erro de alocação na linha %d\n", i);
            // Libera linhas já alocadas antes de sair
            for (int j = 0; j < i; j++)
                free(matriz[j]);
            free(matriz);
            return 1;
        }
    }

    // Leitura da matriz
    printf("Digite os elementos da matriz:\n");
    for (int i = 0; i < linhas; i++)
    {
        for (int j = 0; j < colunas; j++)
        {
            scanf("%d", &matriz[i][j]);
        }
    }

    // Exibe a matriz original
    printf("\nMatriz original:\n");
    for (int i = 0; i < linhas; i++)
    {
        for (int j = 0; j < colunas; j++)
        {
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }

    // Exibe a matriz transposta (linhas e colunas trocados)
    printf("\nMatriz transposta:\n");
    for (int j = 0; j < colunas; j++)
    {
        for (int i = 0; i < linhas; i++)
        {
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }

    // Libera a memória (cada linha e depois o vetor de ponteiros)
    for (int i = 0; i < linhas; i++)
    {
        free(matriz[i]);
    }
    free(matriz);

    return 0;
}