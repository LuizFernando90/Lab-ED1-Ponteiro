#include <stdio.h>

int somaVetor(int *v, int n)
{
    int soma = 0;
    for (int i = 0; i < n; i++)
    {
        soma += *(v + i);
    }
    return soma;
}

int main()
{
    int vetor[] = {10, 20, 30, 40};
    int tam = sizeof(vetor) / sizeof(vetor[0]);
    printf("Soma = %d\n", somaVetor(vetor, tam));
    return 0;
}