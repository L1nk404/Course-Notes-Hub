#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a = 1, b = 2, *pointer = &b;
    printf("Valor de A %d, addr: %p\n", a, &a);
    printf("Valor de B %d, addr: %p\n\n", b, &b);

    printf("valor: ");
    scanf("%d", &a); // input

    printf("\nValor de a %d, addr: %p\n\n", a, &a);
    printf("Esse é pointer de B %X\n\n", pointer);

    return 0;
}