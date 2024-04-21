#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <locale.h>
#define pi 3.14
#define WielkoscTab 20


///f(x)=sin(x)

float *tabwspolcz;
float *tabwynik;
float *tabszum;
float *tabsygnal;
float *tabfiltr;
float *tabokno;

void przebieg();
void wspolcz();
void szum();
void zapisywanie();
void zapisszum();
void odczytsygnal();
void filtrmed();
void wzrost(int n, int i);
void menu();

int main()
{
    setlocale( LC_ALL, "polish_poland" );
    menu();
    return 0;
}

void przebieg(){
    float xMin=tabwspolcz[0];
    float xMax=tabwspolcz[1];
    float amp=tabwspolcz[2];
    float freq=tabwspolcz[3];
    float offset=tabwspolcz[4];
    tabwynik=(float*)malloc(WielkoscTab*sizeof(float));

    float sygnal(float x){
        return amp * sin(x * freq) + offset;
    }

    double step = ( xMax - xMin )/WielkoscTab;
    double xT = xMin;
    for(int i=0; i<WielkoscTab; i++) {
        double point = sygnal(xT);
        tabwynik[i] = point;
        xT += step;
    }
}

void wspolcz(){
    tabwspolcz=(float*)malloc(5*sizeof(float));
    float a=tabwspolcz[0];
    float b=tabwspolcz[1];
    float amp=tabwspolcz[2];
    float freq=tabwspolcz[3];
    float offset=tabwspolcz[4];
    printf("Podaj a: ");
    scanf("%f", &tabwspolcz[0]);
    printf("\nPodaj b: ");
    scanf("%f", &tabwspolcz[1]);
    if(tabwspolcz[1] == tabwspolcz[0]){
        printf("\nPodaj b rozne od a: ");
        scanf("%f", &tabwspolcz[1]);
    }
    printf("\nAmplituda: ");
    scanf("%f", &tabwspolcz[2]);
    if(tabwspolcz[2]==0){
        printf("\nPodaj amplitude (rozne od 0): ");
        scanf("%f", &tabwspolcz[2]);
    }
    printf("\nCzestotliwosc: ");
    scanf("%f", &tabwspolcz[3]);
    if(tabwspolcz[3]==0){
        printf("\nPodaj czestotliwosc (rozne od 0): ");
        scanf("%f", &tabwspolcz[3]);
    }
    printf("\nOffset: ");
    scanf("%f", &tabwspolcz[4]);
}

void szum(){
    tabszum=(float*)malloc(WielkoscTab*sizeof(float));
    srand( time( NULL ) );
    for( int i = 0; i < WielkoscTab; i++ ){
        for ( int t=0; t<WielkoscTab; t++)
            tabszum[i]=tabwynik[t]+rand()%10-5;
    }
}

void zapisywanie(){
    FILE* wyniki;
    wyniki = fopen("sygnal.CSV", "w");
    fprintf(wyniki, "\n");
    for(int i=0; i<WielkoscTab; i++)
        fprintf(wyniki, "%.3f\n", tabwynik[i]);
        //fprintf(wyniki, "\n");
        //for(int t=0; t<WielkoscTab; t++)
        //fprintf(wyniki, "%.3f\n", tabszum[t]);
    fclose(wyniki);
}

void zapisszum(){
    FILE* szum;
    szum = fopen("szum.CSV", "w");
    fprintf(szum, "\n");
    for(int t=0; t<WielkoscTab; t++)
        fprintf(szum, "%.3f; %.3f \n", tabwynik[t], tabszum[t]);
    fclose(szum);
}

void odczytsygnal(){
    FILE* odczyt;
    odczyt = fopen("sygnal.CSV", "r");
    tabsygnal = realloc(tabwynik, WielkoscTab*sizeof(float));
    fclose(odczyt);
    printf("\n");
}

void filtrmed(){
     tabfiltr=(float*)malloc(WielkoscTab*sizeof(float));

    /*
    for(int n=5; n<8; n++){
        for(int i=0; i<3; i++)
                wzrost(n, i);
                tabfiltr[]
        }

    */

    wzrost(5,0);
    //tabfiltr[0]=tabokno[0];
    //tabfiltr[1]=tabokno[1];
    //tabfiltr[2]=tabokno[2];
    for(int k=0; k<5; k++)
        printf("%.3f\n", tabokno[k]);
    printf("\n");
    wzrost(6,1);
    //tabfiltr[3]=tabokno[3];
    for(int k=1; k<6; k++)
        printf("%.3f\n", tabokno[k]);
    printf("\n");
    wzrost(7,2);
    //tabfiltr[4]=tabokno[4];
    for(int k=2; k<7; k++)
        printf("%.3f\n", tabokno[k]);
    printf("\n");
    wzrost(8,3);
    //tabfiltr[5]=tabokno[5];
    for(int k=3; k<8; k++)
        printf("%.3f\n", tabokno[k]);

    //for(int b=0;b<5;b++)
    //    printf("%.3f\n", tabfiltr[b]);
}
void wzrost(int n,int i){
    tabokno=(float*)malloc(WielkoscTab*sizeof(float));

    for(i; i < n; i++){
        tabokno[i]=tabsygnal[i];
    }
    for(int p=0; p < n - 1; p++) {
       for(int j=i; j < n - p - 1 ; j++) {
           if(tabokno[j] > tabokno[j+1]) {
              float tmp = tabokno[j];
              tabokno[j] = tabokno[j+1] ;
              tabokno[j+1] = tmp;
           }
        }
    }
 }

void menu(){
    int a;
    printf("Podaj wspolczyniki do funkcji f(x)=sin(x): \n");
    wspolcz();
    k:
    printf("\nMenu uzytkownika:\n");
    printf("1.Generowanie sygnalu\n");
    printf("2.Wczytanie sygnalu\n");
    printf("3.Zaszumienie sygnalu\n");
    printf("4.Filtracja sygnalu\n");
    k1:
    scanf("%d",&a);
    switch(a){
        case 1:
            przebieg();
            zapisywanie();
            printf("\nSygnal utworzony.\n");
            goto k;
            break;
        case 2:
            przebieg();
            zapisywanie();
            odczytsygnal();
            for(int i=0; i<WielkoscTab; i++)
                printf("%.3f\n", tabsygnal[i]);
            goto k;
            break;
        case 3:
            przebieg();
            szum();
            zapisszum();
            printf("\nZaszumienie utworzone.\n");
            goto k;
            break;
        case 4:
            przebieg();
            szum();
            odczytsygnal();
            filtrmed();
            goto k;
            break;
        default:
            printf("Blad wprowadzania. Sprobuj ponownie: ");
            goto k1;
            break;
    }
}
