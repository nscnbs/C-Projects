#include <stdio.h>
#include <string.h>

int main (){
	int liczba1=0;
	int liczba2=0;
	int liczba3=0;
	int liczba4=0;
	int red;
	int redx;
	int white;
	int whitex;
	int opport[6][6][6][6];
	int kombi = 1296;
	
	for (int a = 0; a < 6; a++){
		for (int b = 0; b < 6; b++){
			for(int c = 0; c < 6; c++){
				for(int d = 0; d < 6; d++){
					opport[a][b][c][d] = 1;
				}
			}
		}
	}

	for (int q=0;q<8;q++){
 		while(opport[liczba1][liczba2][liczba3][liczba4]==0 && kombi>0){
			if(liczba4<5)
				liczba4=liczba4+1;
			else if(liczba4==5){
				liczba4=0;
				if(liczba3 <5)
					liczba3=liczba3+1;	
					else if(liczba3==5){
						liczba3=0;
						if(liczba2<5)
							liczba2=liczba2+1;
						else if(liczba2==5){
							liczba2=0;
							if (liczba1<5)
								liczba1=liczba1+1;
							else if(liczba1==5){
								liczba1=0;
								liczba2=0;
								liczba3=0;
								liczba4=0;
							}

						}
					}
				}
			
		}
		if (kombi <=0){
			printf("You are cheating ! \n");
			break;
	}

	printf("[%d] [%d] [%d] [%d] ? \n",liczba1+1,liczba2+1,liczba3+1,liczba4+1);
	printf ("red : \n");
	scanf ("%d" , &red);
	printf ("white : \n");
	scanf ("%d" , &white);
	if(red==4){
		printf ("I win\n");
		q=8;
	}
	else if(kombi >0){
		opport[liczba1][liczba2][liczba3][liczba4]=0; 
		kombi =kombi-1;
		for(int i=0;i<6;i++){
			for (int z=0 ;z<6;z++){ 
				for (int u=0;u<6;u++){ 
					for(int y=0;y<6;y++){ 
						whitex=0;
			 			redx=0;
						if(liczba1==i)
							redx=redx+1;
						if(liczba2 ==z)
							redx=redx+1;
						if(liczba3== u)
							redx=redx+1;
						if(liczba4==y)
							redx=redx+1;
						if(redx!=red && opport[i][z][u][y]==1){
							opport[i][z][u][y]=0;
							kombi=kombi-1;
						}
						else if(redx==red){
							if(i!=liczba1 && (i==liczba2 || i==liczba3 || i==liczba4))
								whitex=whitex+1;
					 		if(z!=liczba2 && (z==liczba1 || z==liczba3 || z==liczba4))
								whitex=whitex+1;
					 		if(u!=liczba3 && (u==liczba1 || u==liczba2 ||u==liczba4))
								whitex=whitex+1;
							if(y!=liczba4 && (y==liczba1 || y==liczba2 ||y==liczba3))
								whitex =whitex+1;
						}
				 		if(whitex!=white && opport[i][z][u][y]==1){
							opport[i][z][u][y]=0;
							kombi =kombi-1;
						}
					}
		    	}
			} 
		}
	}	 
}

	if(  kombi>0 && red!=4)
	{printf("You win \n");
		}
return 0;
}
