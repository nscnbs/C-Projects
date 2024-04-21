#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include"ln.h"

bool x(char *h)
{
    bool palidron = true;
    size_t dl = strlen(h);

    if (dl == 0)
    {
        palidron = true;
    }
    else
    {
        char *L=h;
        char *P=&h[dl-1];

        while ((L < P) && palidron)
        {
            if (*L != *P)
            {
                palidron=false;
            }
            L++;
            --P;
        }
    }

    return palidron;
}

