#include <stdlib.h>
#include <stdio.h>

#define rozmiar 1000


int main(void){
    int sum=1;
    int wynik[rozmiar]={0};

    for (int n=2;n<rozmiar;n++){
        for (int i=2;i<=n/2;i++){
            if (n%i==0) 
                sum+=i;
        }
        wynik[n]=sum;
        sum=1;    
    }
    
    printf("Liczby doskonale:");
    for (int n=2;n<rozmiar;n++)
        if (n == wynik[n]) 
            printf(" %d; ", n);
 
    for (int n=1;n<rozmiar;n++)
        if (wynik[wynik[n]]==n && n<wynik[n])
            printf("\nLiczby zaprzyjaznione: %d;  %d\n", n, wynik[n]);
}
