#include<stdio.h>
#include"la.h"

int fi(unsigned long int n){ 
    unsigned int y = 1; 
    for(int i = 2; i < n; i++) 
        if(nwd(i,n) == 1) 
            y++; 
    return y; 
} 

