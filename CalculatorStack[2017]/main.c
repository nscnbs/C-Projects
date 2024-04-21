#include <stdio.h>
#include <stdlib.h>

struct zespol{
    char i;
    int ReZ;
    int ImZ;
};

typedef struct newstos s;
struct newstos{
    int liczba1;
    int liczba2;
    s *next;
};

typedef struct newdop dop;
struct newdop{
    s *h;
};

void push(dop *stos,int liczba1, int liczba2);
int pop(dop *stos);
void wyswielt(dop *stos, char k);
int empty(dop *stos);
int dodaj(dop *stos, int liczba1, int liczba2);
int odejmij(dop *stos, int liczba1, int liczba2);
int iloczyn(dop *stos, int liczba1, int liczba2);
int iloraz(dop *stos, int liczba1, int liczba2);
dop St={NULL};

int main(void){
    struct zespol liczbaZ;
    char i;
    liczbaZ.i=i;
    int liczba;
    int menu;
    printf("Kalkulator ONP liczb zespolonych\n");
    k:
    scanf("%d",&menu);
    printf("\n");
    switch(menu){
        case 1:
            if(empty(&St))
                printf("Stos pusty\n\n");
            else
                wyswielt(&St, liczbaZ.i);
            goto k;
        case 2:
            //printf("Podaj liczbe:");
            scanf("%d %d%c",&liczbaZ.ReZ, &liczbaZ.ImZ, &liczbaZ.i);
            push(&St,liczbaZ.ReZ, liczbaZ.ImZ);
            printf("Wrzucono %d %d%c\n\n",liczbaZ.ReZ, liczbaZ.ImZ, liczbaZ.i);
            goto k;
        case 3:
            if(empty(&St))
                printf("Stos pusty\n\n");
            else
                printf("Pobrano %d %d%c\n\n",pop(&St), liczbaZ.i);
            goto k;
        case 4:
            dodaj(&St, liczbaZ.ReZ, liczbaZ.ImZ);

            goto k;
        case 5:
            odejmij(&St, liczbaZ.ReZ, liczbaZ.ImZ);
            goto k;
        case 6:
            iloczyn(&St, liczbaZ.ReZ, liczbaZ.ImZ);
            goto k;
        case 7:
            iloraz(&St, liczbaZ.ReZ, liczbaZ.ImZ);
            goto k;
        case 0:
            break;
    }
}


void push(dop *stos,int liczba1, int liczba2){
    s *tmp=(s*)malloc(sizeof(s));
    if(!tmp)
        exit(fprintf(stderr,"Brak pamieci"));
    tmp->liczba1=liczba1;
    tmp->liczba2=liczba2;
    tmp->next=stos->h;
    stos->h=tmp;
}

int pop(dop *stos){
    s *tmp=stos->h;
    if(!tmp)
        exit(fprintf(stderr,"Pobranie z pustego stosu"));
    stos->h=tmp->next;
    int liczba1=tmp->liczba1;
    int liczba2=tmp->liczba2;
    free(tmp);
    return liczba1; liczba2;
}

void wyswielt(dop *stos, char k){
    for(s *i=stos->h;i;i=i->next)
        printf("%d %d%c\n",i->liczba1, i->liczba2, k);
    printf("\n");
}

int empty(dop *stos){
    return !(stos->h);
}

int dodaj(dop *stos, int liczba1, int liczba2){
    int l1[2];
    int l2[2];
    int k=0;
    char l='i';
    for(s *i=stos->h;i;i=i->next){
        l1[k]=i->liczba1;
        l2[k]=i->liczba2;
        k++;
    }
    liczba1=l1[0]+l1[1];
    liczba2=l2[0]+l2[1];
    printf("%d %d%c\n", liczba1, liczba2, l);
    printf("\n");
    pop(&St);
    pop(&St);
    push(&St, liczba1, liczba2);
}


int odejmij(dop *stos, int liczba1, int liczba2){
    int l1[2];
    int l2[2];
    int k=0;
    char l='i';
    for(s *i=stos->h;i;i=i->next){
        l1[k]=i->liczba1;
        l2[k]=i->liczba2;
        k++;
    }
    liczba1=l1[0]-l1[1];
    liczba2=l2[0]-l2[1];
    printf("%d %d%c\n", liczba1, liczba2, l);
    printf("\n");
    pop(&St);
    pop(&St);
    push(&St, liczba1, liczba2);
}

int iloczyn(dop *stos, int liczba1, int liczba2){
    int l1[2];
    int l2[2];
    int k=0;
    char l='i';
    for(s *i=stos->h;i;i=i->next){
        l1[k]=i->liczba1;
        l2[k]=i->liczba2;
        k++;
    }
    liczba1=l1[0]*l1[1];
    liczba2=l2[0]*l2[1];
    printf("%d %d%c\n", liczba1, liczba2, l);
    printf("\n");
    pop(&St);
    pop(&St);
    push(&St, liczba1, liczba2);
}


int iloraz(dop *stos, int liczba1, int liczba2){
    int l1[2];
    int l2[2];
    int k=0;
    char l='i';
    for(s *i=stos->h;i;i=i->next){
        l1[k]=i->liczba1;
        l2[k]=i->liczba2;
        k++;
    }
    liczba1=l1[0]/l1[1];
    liczba2=l2[0]/l2[1];
    printf("%d %d%c\n", liczba1, liczba2, l);
    printf("\n");
    pop(&St);
    pop(&St);
    push(&St, liczba1, liczba2);
}
