#include <stdio.h>
#include <math.h>

struct calc{
    float x,y,p,od,rok,m,s;
    char znak;
};

struct osoba{
    char imie[20];
    char nazwisko[20];
    char tel[20];
    int m;
    int suma;
};

struct osoba newosoba;
struct calc kred;
int kredyt();
void dane();
void wypisywanie();

int main(void){
    struct calc k;
        char sign='+';
        k1:
        while (sign != '0') {
            scanf("%c%*c", &sign);
            if (sign == '0') { break; }
            if (sign == '+' || sign == '-' || sign == '*' || sign == '/' || sign == '%') {
                if(sign=='%') goto k2;
                scanf("%f%*c", &k.x);
                scanf("%f%*c", &k.y);
                switch (sign) {
                    case '+':
                        printf("%.2f\n", k.x+k.y);
                        break;
                    case '-':
                        printf("%.2f\n", k.x-k.y);
                        break;
                    case '*':
                        printf("%.2f\n", k.x*k.y);
                        break;
                    case '/':
                        if (k.y != 0) printf("%.2f\n", k.x/k.y);
                        else printf("Dzielienie na 0\n");
                    case '%':
                        k2:
                        dane();
                        kredyt();
                        wypisywanie();
                        printf("\n Powrot do kalkulatora");
                        goto k1;
                }
               printf("\n");
            }
            else printf("Niepoprawny znak\n");
        }
    }

int kredyt(){
    printf("Wielkosc pozyczki: ");
    scanf("%f", &kred.p);
    printf("Odsetek: ");
    scanf("%f", &kred.od);
    printf("Ilosc lat: ");
    scanf("%f", &kred.rok);

    kred.od = kred.od / 100;
    kred.m = (kred.p * kred.od * pow((1+kred.od),kred.rok)) / (12 * (pow(1+kred.od,kred.rok) - 1));
    kred.s = kred.m * 12 * kred.rok;
    printf("Miesieczna wyplata: %.0f zl.\nOgolem bedzie wyplacono: %.0f zl.\n", kred.m, kred.s);
}

void dane(){
    scanf("%s", newosoba.imie);
    scanf("%s", newosoba.nazwisko);
    scanf("%s", newosoba.tel);
}

void wypisywanie(){
    printf("Dane po kredytu:\n");
    printf("%s %s\nNumer tel: %s\n", newosoba.imie, newosoba.nazwisko, newosoba.tel);
    printf("Miesieczna wyplata:%d\nSuma wyplaty:%d", kred.m, kred.s);

}

