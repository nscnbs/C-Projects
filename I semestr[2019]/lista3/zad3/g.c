#include<stdio.h>
#include"la.h"
int nwd(int a,int b) {
    if (a==0) 
        return b; 
    return nwd(b%a,a); 
} 

