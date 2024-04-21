#include <stdlib.h>
#include <stdio.h>


void p(int *x, int y);


int main(void){
    int n;
    float a;
    float sr;
    float sum=0;
    printf("Podaj n: ");
    scanf("%d", &n);
    //a = rand()%50;
    printf("Podaj liczby:\n");
    //scanf("%d", &a);
    //printf("%d", a);
    for(int i=0; i<n; i++){
        //b = rand()%50;
        scanf("%f", &a);
        //printf("%d", b);
        //p(&a, b);
        sum += a;
    }
    printf("\nSuma liczb: %.2f", sum);
    sr = sum/n;
    printf("\nSr.aryfmetyczna: %.2f\n", sr);
}


void p(int *x, int y){
	*x = *x+y;
}

