#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <conio.h>

struct ks {
           char imie[50];
           char nazwisko[50];
          char miasto[50];
          char klasa[50];
          char ksywa[25];
          char nr[25];
          int dli, dln, dlm, dlkl, dlks, dlnr;
           } baza[1000];
int il, a, b, c, d, e, f;
 FILE *in, *out;

int pi[66];

//void printi(char )

void cmp(char w[], int N) {
         int i, j;
         pi[0]=-1;
         for(i=0, j=-1; i<N; i++, j++, pi[i]=j)
         while(j>=0 && w[i]!=w[j])
         j=pi[j];
         }

int kmp(char w[], char t[]) {
        int M=strlen(w), N=strlen(t), i, j;
        for(i=0,j=0;i<N && j<M;i++,j++)
        while((j>=0)&&(t[i]!=w[j])) j=pi[j];
 if (j==M) return i-M; else return -1;

        }


int por(char k[], char l[]) {
   //if(strlen(k)!=strlen(l)) return 0;
   cmp(l, strlen(l));
   int z=kmp(l, k);
   if(z!=-1) return 1;
   else return 0;
        }

char im(struct ks a, struct ks b) {
 for(int c=0; c<min(strlen(a.imie), strlen(b.imie)); c++) {
        if(a.imie[c]!=b.imie[c]) return a.imie[c]<b.imie[c]; }
        }
char nazw(struct ks a, struct ks b) {
                for(int c=0; c<min(strlen(a.nazwisko), strlen(b.nazwisko)); c++) {
        if(a.nazwisko[c]!=b.nazwisko[c]) return a.nazwisko[c]<b.nazwisko[c]; }
        }
char miast(struct ks a,struct ks b) {
        for(int c=0; c<min(strlen(a.miasto), strlen(b.miasto)); c++) {
        if(a.miasto[c]!=b.miasto[c]) return a.miasto[c]<b.miasto[c]; }
        }

void wypisz() {
         for(int a=0; a<il; a++) { printf("%d. \n%s%s%s%s%s%s---------------------\n", a+1, baza[a].imie, baza[a].ksywa,  baza[a].nazwisko, baza[a].miasto, baza[a].klasa, baza[a].nr);
         if(a%3==2) system("PAUSE");
         }
                 getch();
         }

void save() {
                         out=fopen("db.txt", "w");
                fprintf(out, "%d\n", il);
                                 for(a=0; a<il; a++) {
                                 fputs(baza[a].imie, out);
                                 fputs(baza[a].nazwisko, out);
                                 fputs(baza[a].ksywa, out);
                                 fputs(baza[a].miasto, out);
                                 fputs(baza[a].klasa, out);
                                 fputs(baza[a].nr, out);
                                 }
                                 fclose(out);
         }
void open() {
         in=fopen("db.txt", "r");
                         fscanf(in, "%d", &il);
                char dupa[30];
                fgets(dupa, 30, in);
                for(a=0; a<il; a++) {
                                 fgets(baza[a].imie, 40, in);
                                 baza[a].dli=strlen(baza[a].imie);
                                 fgets(baza[a].nazwisko, 40, in);
                                 baza[a].dln=strlen(baza[a].nazwisko);
                                 fgets(baza[a].ksywa, 20, in);
                                 baza[a].dlks=strlen(baza[a].ksywa);
                                 fgets(baza[a].miasto, 40, in);
                                 baza[a].dlm=strlen(baza[a].miasto);
                                 fgets(baza[a].klasa, 40, in);
                                 baza[a].dlkl=strlen(baza[a].klasa);
                                 fgets(baza[a].nr, 20, in);
                                 baza[a].dlnr=strlen(baza[a].nr);
                                 }
                                // sort(baza, baza+il, gat);
                                // wypisz();
                fclose(in);

         }


void search(int poco, char tr[]) {
         int a, b=0;
         if(poco==1) {
                                 for(a=0; a<il; a++) {
                                 if(por(baza[a].imie, tr)) {
                                 printf("%d. \n%s%s%s%s%s%s---------------------\n", a+1, baza[a].imie, baza[a].ksywa, baza[a].nazwisko, baza[a].miasto, baza[a].klasa, baza[a].nr);}
                                 if(b%3==2) system("PAUSE");
                                 b++;
                                 }
                                 }

         else if(poco==2) {
                  for(a=0; a<il; a++) {
                                 if(por(baza[a].nazwisko, tr)) {
                                 printf("%d. \n%s%s%s%s%s%s---------------------\n", a+1, baza[a].imie, baza[a].ksywa, baza[a].nazwisko, baza[a].miasto, baza[a].klasa, baza[a].nr);}
                                 if(b%3==2) system("PAUSE");
                                 b++;
                                 }
                  }

         else if(poco==3) {
                  for(a=0; a<il; a++) {
                                 if(por(baza[a].miasto, tr)) {
                                 printf("%d. \n%s%s%s%s%s%s---------------------\n", a+1, baza[a].imie, baza[a].ksywa, baza[a].nazwisko, baza[a].miasto, baza[a].klasa, baza[a].nr);}
                                 if(b%3==2) system("PAUSE");
                                 b++;
                                 }
                                 }
///////////////
         else if(poco==4) {
                  for(a=0; a<il; a++) {


                                 if(por(baza[a].ksywa, tr)==1 && baza[a].ksywa[0]!='<') {
                                 printf("%d. \n%s%s%s%s%s%s---------------------\n", a+1, baza[a].imie, baza[a].ksywa, baza[a].nazwisko, baza[a].miasto, baza[a].klasa, baza[a].nr);}
                                 if(b%3==2) system("PAUSE");
                                 b++;
                                 }


                                 }


///////////////
                getch();


         }
void menu() {
         printf("1. Wcztaj baze\n");
         printf("2. Zapisz zmiany\n");
         printf("3. Wypisz\n");
         printf("4. Sortuj po imieniu\n");
         printf("5. Sortuj po nazwisku\n");
         printf("6. Sortuj po miescie\n");
         printf("7. Szukaj:\n");
         printf("8. Dodaj\n");
         printf("0. Wyjscie\n");
         }
void menu_s() {
         printf("1. po imieniu\n");
         printf("2. po nazwisku\n");
         printf("3. po miescie\n");
         printf("4. po ksywie\n");
         }
void dodaj() {
         printf("podaj imie:\n");
         gets(baza[il].imie);
         baza[il].imie[strlen(baza[il].imie)]='\n';
         printf("podaj nazwisko:\n");
         gets(baza[il].nazwisko);
         baza[il].nazwisko[strlen(baza[il].nazwisko)]='\n';
         printf("podaj ksywke(lub wpisz <brak>):\n");
         gets(baza[il].ksywa);
         baza[il].ksywa[strlen(baza[il].ksywa)]='\n';
         printf("podaj miasto:\n");
         gets(baza[il].miasto);
         baza[il].miasto[strlen(baza[il].miasto)]='\n';
         printf("podaj klase:\n");
         gets(baza[il].klasa);
         baza[il].klasa[strlen(baza[il].klasa)]='\n';
         printf("podaj nr:\n");
         gets(baza[il].nr);
         baza[il].nr[strlen(baza[il].nr)]='\n';
         il++;
         }


void przyw(int a) {
         printf("%d %d %d %d %d %d\n", baza[a].dli, baza[a].dln, baza[a].dlks, baza[a].dlm, baza[a].dlkl, baza[a].dlnr);
         baza[a].imie[baza[a].dli-1]='\0';


         baza[a].nazwisko[baza[a].dln-1]='\0';

         baza[a].ksywa[baza[a].dlks-1]='\0';

         baza[a].miasto[baza[a].dlm-1]='\0';

         baza[a].klasa[baza[a].dlkl-1]='\0';

         baza[a].nr[baza[a].dlnr-1]='\0';

         }

void ent(int a) {
                  baza[a].imie[baza[a].dli-1]='\n';


         baza[a].nazwisko[baza[a].dln-1]='\n';

         baza[a].ksywa[baza[a].dlks-1]='\n';

         baza[a].miasto[baza[a].dlm-1]='\n';

         baza[a].klasa[baza[a].dlkl-1]='\n';

         baza[a].nr[baza[a].dlnr-1]='\n';

         }


void testuj(int a) {

         printf("%d %d %d %d %d %d\n", baza[a].dli, baza[a].dln, baza[a].dlks, baza[a].dlm, baza[a].dlkl, baza[a].dlnr);

         system("PAUSE");
         }

int main() {
   int z;
                char x, y;
                int n;
                char al[100];
                while(x!=27) {
                        clrscr();
                                  menu();
                x=getch();
                clrscr();

                switch(x) {
                                  case 49: { open();
                                //  for(z=0; z<il; z++) przyw(z);
                                  break; }
                                  case 50: { save();
                                //  for(z=0; z<il; z++) ent(z);
                                   break; }
                                  case 51: { wypisz(); break; }
                                  case 52: {
                          //    for(z=0; z<il; z++) przyw(z);
                                  sort(baza, baza+il, im);
                           //   for(z=0; z<il; z++) przyw(z);
                                  break; }
                                  case 53: {
                         //      for(z=0; z<il; z++) przyw(z);
                                  sort(baza, baza+il, nazw);
                                //  for(z=0; z<il; z++) przyw(z);
                                  // system("PAUSE");
                                   break; }
                                  case 54: {
                          //    for(z=0; z<il; z++) przyw(z);
                                  sort(baza, baza+il, miast);
                           //   for(z=0; z<il; z++) przyw(z);
                                  break; }
                                  case 55: {clrscr();
                                           menu_s();
                                        //   scanf("%d", &n);
                                        //   gets(al);
                                   //   search(n, al);
                                        y=getch();
                                  switch(y) {
                                                        case 49: { gets(al); search(1, al); break; }
                                                        case 50: { gets(al); search(2, al); break; }
                                                        case 51: { gets(al); search(3, al); break; }
                                                        case 52: { gets(al); search(4, al); break; }
                                                        case 53: {testuj(0); break;}
                                                        }
                                   break;
                                   }
                                   case 56: {dodaj(); break;}

                                  case 48: {exit(1); break; }
                                   }

                }

                          getchar();getchar();
        return 0;
        }
