// gcc library_rec.c main_rec.c -o program -std=c99

#include "library_rec.h"
#include <stdio.h>

int main()
{
    printf("Implementacja Rekursja in C");
    // Factorial
    int n = 5;
    printf("%d! = %d\n", n, factorial(n));

    // NWD
    int num1 = 36, num2 = 48;
    printf("NWD: %d i %d = %d\n", num1, num2, nwd(num1, num2));

    // Diofantic
    int a = 120, b = 144, c = 72; // x = -3, y = 3
    // int a = 18, b = 24, c = 30; // x = -5, y = 5
    // int a = 120, b = 144, c = 71; // brak
    DiofanticResult result = diofantic(a, b, c);
    if (result.x != -1 && result.y != -1)
    {
        printf("Rozwiazanie rownania %dx + %dy = %d to x = %d, y = %d\n", a, b, c, result.x, result.y);
    }
    else
    {
        printf("Brak rozwiazania dla rownania %dx + %dy = %d\n", a, b, c);
    }

    return 0;
}