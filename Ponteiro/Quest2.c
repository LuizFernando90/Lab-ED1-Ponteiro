#include <stdio.h>

int main()
{
    int n = 5;
    int *p = &n; // p aponta para n

    *p = 20; // altera n através do ponteiro

    printf("Novo valor de n: %d\n", n);
    return 0;
}