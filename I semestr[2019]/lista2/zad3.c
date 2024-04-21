#include <stdlib.h>
#include <stdio.h>
#include <math.h>


int main(void){
    float sum = 0;
    int n=0;

    //for (n = 1; sum < 10; n++){
    while(sum <= 10){    
        n++;
        sum += (1.0/n);
    }
    printf("Liczba: %d\n", n);
}
