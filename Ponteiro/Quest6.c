#include <stdio.h>

int main()
{
    int v[5] = {1, 2, 3, 4, 5};
    int *p = v; // p aponta para o primeiro elemento

    for (int i = 0; i < 5; i++)
    {
        printf("%d ", *(p + i)); // acessa usando aritmética
    }
    printf("\n");
    return 0;
}