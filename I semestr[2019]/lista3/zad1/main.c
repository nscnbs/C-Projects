#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include"ln.h"

int main(int j, const char * k[]) {
    char y[BUFSIZ];
    bool Palidron;

    printf("Podaj Wyraz\n");
    scanf("%s", y);
    Palidron = x(y);
    printf("Wyraz %s %s jest palidronem\n", y, (Palidron? "" : "Nie"));

}
