#include <stdio.h>

int main()
{
    int x = 10;
    int *p;

    p = &x; // p aponta para x

    printf("Valor de x: %d\n", x);
    printf("Endereço de x: %p\n", (void *)&x);
    printf("Valor armazenado em p (endereço): %p\n", (void *)p);
    printf("Valor apontado por p: %d\n", *p);

    return 0;
}