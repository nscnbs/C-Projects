#include<math.h>
#include"funs.h"
int main(){
	double a,b,eps,srodek;
	printf("podaj a: ");
	scanf("%lf", &a);
	printf("podaj b: ");
	scanf("%lf", &a);
	printf("podaj epsilon: ");
	scanf("%lf", &eps);
	printf("znalezione miejsce wynosi: \n");
	srodek=rozwiazanie(a, b, eps);
	printf("%lf\n", srodek);
	return 0;
}

