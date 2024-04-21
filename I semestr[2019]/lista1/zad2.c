//Zad2

#include <stdio.h>
#include <math.h>

int main(void){
float a,b,c,delta;
printf("Podaj wspolczynnik a: ");
scanf("%f",&a);
printf("Podaj wspolczynnik b: ");
scanf("%f",&b);
printf("Podaj wspolczynnik c: ");
scanf("%f",&c);
delta = (b*b)-(4*a*c);
printf("Delta: %.2f\n", delta);
if(a == 0)
    printf("To nie rownanie kwadratowe\n");
else if(delta == 0)
    printf("Jedno rozwiazanie x = %.2f\n",(-b)/(2*a));
else if(delta >= 0){
    printf("Pierwsze rozwiazanie x = %.2f\n",(-b-delta)/(2*a));
    printf("Drugie rozwiazanie x = %.2f\n",(-b+delta)/(2*a));
    }
else if(delta <= 0)
    printf("Brak rozwiazan\n");           
}