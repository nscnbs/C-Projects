#include <stdlib.h>
#include <stdio.h>
#include <math.h>


void zapis(int a, double b);
void clear(); 
int NWD(int a, int b);
int NWW(int a, int b);


int main(void){
    clear();
    int n=1000;
    int funk=0;
    int count=1;
    double arg;
    
    for(int i = 1; i <= n; i++){  
        for (int j = 1; j < i; j++){
            if (NWD(j,i) == 1) {
                funk += 2; 
            }
        }
        count += funk;
        funk = 0;
        arg = (double) count/i/i;
        zapis(i, arg);
        //printf("%d; %f\n", i, arg); 
    }
 
}


void zapis(int a, double b){
    FILE *zad5;
    zad5=fopen("wykres.csv", "a");
    fprintf (zad5, "%d; %f\n", a, b);
    fclose (zad5);
}


void clear(){
    FILE *zad5;
    zad5=fopen("wykres.csv", "w");
    fclose (zad5);   
}


int NWD(int a, int b){ 
    if (b == 0) return a;
    else return NWD(b,(a % b));
}


int NWW(int a, int b){
    return a * b / NWD(a,b);
}
