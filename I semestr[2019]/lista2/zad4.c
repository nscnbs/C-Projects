#include <stdlib.h>
#include <stdio.h>
#include <math.h>


int main(void){
    double res=1;

    for(double n=1; n <= 1000; n++){
        res *= (pow(n,(1.0/1000.0)));
    }
    printf("%f", res);
}