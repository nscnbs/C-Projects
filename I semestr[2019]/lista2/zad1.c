#include <stdlib.h>
#include <stdio.h>


int main(void){
    int zl, gr;
    int bank[8] = {200,100,50,20,10,5,2,1};
    int monety[6] = {50,20,10,5,2,1};
    printf("\nPodaj liczbe zloty: ");
    scanf("%d", &zl);
    printf("Podaj liczbe groszy: ");
    scanf("%d", &gr);
    if(gr >= 100){
        printf("Podaj groszy ponizej 100: ");
        scanf("%d", &gr);
    }
    printf("\nKwota: %d zl %d gr", zl, gr);
    printf("\nBanknoty:\n");
    for (int i = 0; i<8; i++){
        int a = zl/bank[i];
        if(a != 0)
            printf("\t%d x %d zl\n", a, bank[i]);
        zl = zl-a*bank[i];
        if (i == 4) 
            printf("\nMonety:\n");
    }
    for (int i = 0; i<6; i++){
        int a = gr/monety[i];
        if(a != 0)
            printf("\t%d x %d gr\n", a, monety[i]);
        gr = gr-a*monety[i];
    }
}
