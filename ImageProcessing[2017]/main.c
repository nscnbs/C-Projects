#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include "obraz.h"

#define SIZE 1024

void menu();
int czytaj(FILE *p,int **obraz2,int *X,int *Y, int *szarosci);
void zapis(int **obraz, int X, int Y, int szarosci);
void negatyw (int **obraz2,int *X,int *Y, int *szarosci);
void progowanie (int **obraz2, int *X,int *Y, int *szarosci);
int odbicie(FILE *p,int **obraz2,int *X,int *Y, int *szarosci);
void obrot(int **obraz2,int *X,int *Y,int *szarosci);
void szum(int **obraz2, int *X,int *Y, int *szarosci);
void histogram(int **obraz,int X,int Y,int szarosci);

int main(void){
    menu();
}

void histogram(int **obraz,int X,int Y,int szarosci){
    int i,j;
    FILE* histogram;
    histogram = fopen("histogram.CSV", "w");
    fprintf(histogram, "P2\n%d; %d\n %d;",X,Y,szarosci);
    for (j=0;j<Y;j++) {
        for (i=0;i<X;i++)
            fprintf(histogram, "%d; ",obraz[i][j]);
    }
    fclose(histogram);
}

void szum(int **obraz2, int *X,int *Y, int *szarosci){
    srand( time( NULL ) );
    for(int j=0; j < *Y; j++){
        for (int i=0; i < *X; i++)
            obraz2[i][j]=obraz2[i][j+(rand()%201)/100];
    }
}

int czytaj(FILE *p,int **obraz2,int *X,int *Y, int *szarosci) {
    char *s;
    s=malloc(SIZE*sizeof(char));
    int znak,koniec=0,i,j;
    if (p==NULL){
        fprintf(stderr,"Nie podano uchwytu do pliku\n");
        return(0);
    }
    if (fgets(s,SIZE,p)==NULL)
        koniec=1;
    if ( (s[0]!='P') || (s[1]!='2') || koniec) {
        fprintf(stderr,"To nie jest plik PGM\n");
        return(0);
    }
    do{
        if ((znak=fgetc(p))=='#'){
            if (fgets(s,SIZE,p)==NULL)
                koniec=1;
        }
        else{
            ungetc(znak,p);
        }
    }while(!koniec && znak=='#');

    if (fscanf(p,"%d %d %d",X,Y,szarosci)!=3) {
        fprintf(stderr,"Brak wymiarow obrazu lub liczby stopni szarosci\n");
        return(0);
    }
    for (i=0;i<*X;i++) {
        for (j=0;j<*Y;j++) {
            if (fscanf(p,"%d",&(obraz2[i][j]))!=1) {
                fprintf(stderr,"Niewlasciwe wymiary obrazu\n");
                return(0);
            }
        }
    }
    return *X**Y;
}
void odbicie2(int **obraz2,int *X,int *Y,int *szarosci){

}

int odbicie(FILE *p,int **obraz2,int *X,int *Y, int *szarosci) {
    char *s;
    s=malloc(SIZE*sizeof(char));
    int znak,koniec=0,i,j;
    if (p==NULL){
        fprintf(stderr,"Nie podano uchwytu do pliku\n");
        return(0);
    }
    if (fgets(s,SIZE,p)==NULL)
        koniec=1;
    if ( (s[0]!='P') || (s[1]!='2') || koniec) {
        fprintf(stderr,"To nie jest plik PGM\n");
        return(0);
    }
    do{
        if ((znak=fgetc(p))=='#'){
            if (fgets(s,SIZE,p)==NULL)
                koniec=1;
        }
        else{
            ungetc(znak,p);
        }
    }while(!koniec && znak=='#');

    if (fscanf(p,"%d %d %d",X,Y,szarosci)!=3) {
        fprintf(stderr,"Brak wymiarow obrazu lub liczby stopni szarosci\n");
        return(0);
    }
    for (i=0;i<*X;i++) {
        for (j=0;j<*Y;j++) {
            if (fscanf(p,"%d",&(obraz2[i][j]))!=1) {
                fprintf(stderr,"Niewlasciwe wymiary obrazu\n");
                return(0);
            }
        }
    }
    return *X**Y;
}

void obrot(int **obraz2,int *X,int *Y,int *szarosci){
    int kat=90;
    int s=sin(kat);
    int c=cos(kat);
    int newX;
    int newY;
/*
    if (s>=0 && c>=0){
        newX=*Y*s;
        newY=0;
    }
    else if(s<=0 && c<=0){
        newX=c*(-*X);
        newY=c*(-*Y)- s**X;
    }
    else if(s>=0 && c<=0){
        newX=*Y*s-*X*c;
        newY=*Y*(-c);
    }
    else{
        newX=0;
        newY=s*(-*X);
    }
    int i,j;
    for (j=0;j<newY;j++) {
        for (i=0;i<newX;i++)
            obraz2[i][j];
    }
*/
    for (int j = 0; j < *Y; j++){
        for (int i = 0; i < *X; i++){
            newX = *X*c - *Y*s;
            newY = *X*s + *Y*c;
            if (newX >= 0 && newX < *X && newY >= 0 && newY < *Y) {
                obraz2[i][j] = obraz2[newX][newY];
            }
            else {
                obraz2[i][j];
            }
        }
    }
}

void progowanie (int **obraz2,int *X,int *Y, int *szarosci) {
    int i,j,prog;
    printf("Wybierz stopien progowania w przedziale 0 do %d: ", *szarosci);
    scanf("%d", &prog);
    if(prog<=*szarosci && prog>=0){
        for (j=0;j<*Y;j++) {
            for (i=0;i<*X;i++) {
                if (obraz2[i][j]<=prog)
                    obraz2[i][j]=0;
                else
                    obraz2[i][j]=*szarosci;
            }
        }
    }
    else{
        printf("Podano zly stopien progowania");}
}

void negatyw(int **obraz2,int *X,int *Y,int *szarosci){
    int i,j;
    for (j=0;j<*Y;j++) {
        for (i=0;i<*X;i++)
            obraz2[i][j]=(*szarosci-obraz2[i][j]);
    }
}

void zapis(int **obraz,int X,int Y,int szarosci){
    int i,j;
    FILE *plik;
    char *nazwa;
    nazwa=malloc(100*sizeof(char));
    printf("Podaj nazwe pliku: \n");
    scanf("%s",nazwa);
    plik=fopen(nazwa,"w");
    fprintf(plik, "P2\n%d %d\n%d ",X,Y,szarosci);
    for (j=0;j<Y;j++) {
        for (i=0;i<X;i++)
            fprintf(plik, "%d ",obraz[i][j]);
    }
}

void menu(){
    int X,Y,p,a;
    int **obraz;
    obraz=malloc(SIZE*sizeof(*obraz));
    for(int i=0; i<SIZE; i++){
        obraz[i]=malloc(SIZE*sizeof(obraz));
    }
    int odczytano = 0;
    FILE *plik;
    FILE *plik1;
    char *nazwa;
    nazwa=malloc(100*sizeof(char));
    printf("Podaj nazwe pliku:\n");
    scanf("%s",nazwa);
    plik=fopen(nazwa,"r");
    if (plik != NULL)
        odczytano = czytaj(plik,obraz,&X,&Y,&p);
    if (odczytano != 0){
        k:
        printf("\n1. Wczytaj inny plik\n");
        printf("2. Odbicie obrazu\n");
        printf("3. Obrot obrazu\n");
        printf("4. Stworz negatyw obrazu\n");
        printf("5. Wyproguj obraz\n");
        printf("6. Zaszumienie obrazu\n");
        printf("7. Zapisz\n");
        printf("8. END\n\n");
        k1:
        scanf("%d", &a);
        switch(a){
            case 1:{
                printf("Podaj nazwe pliku:\n");
                scanf("%s",nazwa);
                plik=fopen(nazwa,"r");
                if (plik != NULL)
                    odczytano = czytaj(plik,obraz,&X,&Y,&p);
                goto k;
                break;
            }
            case 2:{
                plik=fopen("test.PGM","r");
                if (plik != NULL)
                    odczytano = odbicie(plik,obraz,&X,&Y,&p);
                printf("\nUtworzone.\n");
                goto k;
                break;
            }
            case 3:{
                obrot(obraz,&X,&Y,&p);
                printf("\nUtworzone.\n");
                goto k;
                break;
            }
            case 4:{
                negatyw(obraz,&X,&Y,&p);
                printf("\nUtworzone.\n");
                goto k;
                break;
            }
            case 5:{
                progowanie(obraz,&X,&Y,&p);
                printf("\nUtworzone.\n");
                goto k;
                break;
            }
            case 6:{
                szum(obraz,&X,&Y,&p);
                printf("\nUtworzone.\n");
                goto k;
                break;
            }
            case 7:{
                zapis(obraz,X,Y,p);
                printf("\nObraz zapisany\n");
                goto k;
                break;
            }
            case 8:{
                histogram(obraz,X,Y,p);
                break;
            }
            default:{
                printf("Blad wprowadzania. Sprobuj ponownie: \n");
                goto k1;
                break;
            }
        }
    }
    fclose(plik);
}



/*
    obraz2=malloc(SIZE*sizeof(*obraz2));
    for(int k=0; k<SIZE; k++)
        obraz2[k]=malloc(SIZE*sizeof(obraz2));
*/
