//Zad 4

#include <stdio.h>
int main(void) {
   int i, space, n, k = 0;
   printf("Podaj n: ");
   scanf("%d", &n);
   for (i = 1; i <= n; i++, k = 0) {
      for (space = 1; space <= n - i; space++) {
         printf("  ");
      }
      while (k != 2 * i - 1) {
         printf("* ");
         ++k;
      }
      printf("\n");
   }
}
