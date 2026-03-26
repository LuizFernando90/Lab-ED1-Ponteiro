#include <stdio.h>

int maior(int *a, int *b)
{
    return (*a > *b) ? *a : *b;
}

int main()
{
    int x = 42, y = 17;
    printf("Maior: %d\n", maior(&x, &y));
    return 0;
}