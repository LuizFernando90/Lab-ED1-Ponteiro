#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n;
    printf("Digite o tamanho do vetor: ");
    scanf("%d", &n);

    // Aloca dinamicamente um vetor de inteiros
    int *vetor = (int *)malloc(n * sizeof(int));
    if (vetor == NULL)
    {
        printf("Erro de alocação de memória!\n");
        return 1;
    }

    // Leitura dos elementos
    printf("Digite os %d elementos:\n", n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &vetor[i]); // ou vetor + i
    }

    // Impressão na ordem inversa
    printf("Vetor na ordem inversa:\n");
    for (int i = n - 1; i >= 0; i--)
    {
        printf("%d ", vetor[i]);
    }
    printf("\n");

    free(vetor); // Libera a memória alocada
    return 0;
}