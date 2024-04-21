// zad1.c
#include "library_rec.h"
#include <stdio.h>

int factorial(int n)
{
    if (n == 0 || n == 1)
    {
        return 1;
    }
    else
    {
        return n * factorial(n - 1);
    }
}

int nwd(int a, int b)
{
    if (b == 0)
        return a;
    else
        return nwd(b, a % b);
}

DiofanticResult diofantic(int a, int b, int c)
{
    DiofanticResult result;

    // Sprawdzamy bazowy przypadek, gdy a i b są równe 0, wtedy równanie nie ma rozwiązania
    if (a == 0 && b == 0)
    {
        result.x = -1; // Sygnalizujemy brak rozwiązania
        result.y = -1;
        return result;
    }

    // Bazowy przypadek, gdy a lub b jest równe 0
    if (a == 0)
    {
        if (c % b == 0)
        {
            result.x = 0;
            result.y = c / b;
            return result;
        }
        else
        {
            result.x = -1; // Sygnalizujemy brak rozwiązania
            result.y = -1;
            return result;
        }
    }

    if (b == 0)
    {
        if (c % a == 0)
        {
            result.x = c / a;
            result.y = 0;
            return result;
        }
        else
        {
            result.x = -1; // Sygnalizujemy brak rozwiązania
            result.y = -1;
            return result;
        }
    }

    // Rozwiązanie rekurencyjne
    int gcd = nwd(a, b);
    if (c % gcd != 0)
    {
        result.x = -1; // Sygnalizujemy brak rozwiązania
        result.y = -1;
        return result;
    }

    // Rozwiązanie za pomocą algorytmu Eulera
    DiofanticResult tempResult = diofantic(b, a % b, c);
    if (tempResult.x == -1 && tempResult.y == -1)
    {
        result.x = -1; // Sygnalizujemy brak rozwiązania
        result.y = -1;
        return result;
    }

    result.x = tempResult.y;
    result.y = tempResult.x - (a / b) * tempResult.y;

    return result;
}
