#include<stdio.h>
#include"funs.h"

double rozwiazanie(double a, double b, double eps){
		double srodek;
	
	while(b-a>eps){
		srodek=(a+b)/2;
		if (f(srodek)==0)
			return srodek;
		if (f(a)*f(srodek)<0)
			b=srodek;
		else
			a=srodek;
	}
		return b;
}


