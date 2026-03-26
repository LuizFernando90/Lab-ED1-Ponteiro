#include <stdio.h>

void soma(int *a, int *b, int *resultado)
{
    *resultado = *a + *b;
}

int main()
{
    int x = 7, y = 3, res;
    soma(&x, &y, &res);
    printf("Soma: %d\n", res);
    return 0;
}