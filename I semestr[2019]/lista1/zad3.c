//Zad 3

#include <stdio.h>
int main(void) {
   int i, j, n;
   printf("Podaj n: ");
   scanf("%d", &n);
   for (i = 0; i != n; i++) {
      for (j = 0; j != 2*n; j++) {
         printf("*");
      }
      printf("\n");
   }
}
