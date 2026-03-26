#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n;
    printf("Digite o tamanho do vetor: ");
    scanf("%d", &n);

    // Aloca memória dinamicamente
    int *vetor = (int *)malloc(n * sizeof(int));
    if (vetor == NULL)
    {
        printf("Erro de alocação!\n");
        return 1;
    }

    // Leitura dos valores
    printf("Digite %d números:\n", n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", vetor + i); // usando aritmética de ponteiros
    }

    // Cálculo da média
    int soma = 0;
    for (int i = 0; i < n; i++)
    {
        soma += *(vetor + i);
    }
    double media = (double)soma / n;

    printf("Média = %.2f\n", media);

    // Libera a memória
    free(vetor);

    return 0;
}