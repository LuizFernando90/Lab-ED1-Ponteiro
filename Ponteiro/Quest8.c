#include <stdio.h>

int maiorElemento(int *v, int n)
{
    int maior = *v; // primeiro elemento
    for (int i = 1; i < n; i++)
    {
        if (*(v + i) > maior)
        {
            maior = *(v + i);
        }
    }
    return maior;
}

int main()
{
    int vetor[] = {3, 8, 1, 9, 2};
    int tam = sizeof(vetor) / sizeof(vetor[0]);
    printf("Maior elemento: %d\n", maiorElemento(vetor, tam));
    return 0;
}