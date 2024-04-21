#include<stdio.h>
#include"la.h"
int main() { 
    int n,z,d=0;
	scanf("%d", &z);
	for (n = 1; n <= z-1; n++)
	d++;
        printf("fi(%d) = %d\n", n, fi(n));
    return 0; 
} 

