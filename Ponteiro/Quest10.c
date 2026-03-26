#include <stdio.h>

void inverter(int *v, int n)
{
    int *inicio = v;
    int *fim = v + n - 1;

    while (inicio < fim)
    {
        int temp = *inicio;
        *inicio = *fim;
        *fim = temp;
        inicio++;
        fim--;
    }
}

int main()
{
    int v[] = {1, 2, 3, 4, 5};
    int n = sizeof(v) / sizeof(v[0]);

    inverter(v, n);

    printf("Vetor invertido: ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", v[i]);
    }
    printf("\n");
    return 0;
}