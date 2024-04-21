#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<locale.h>

struct kontakty{
	char imie[20];
	char nazwisko[20];
	char numer[20];
	char grupa[20];
};

typedef struct element_listy{
	struct kontakty dane;
	struct element_listy *poprzedni;
	struct element_listy *nastepny;
}kontakt;

void duplikat(kontakt **poczatek);
void wyswietl(struct element_listy **poczatek);
void newplace(char co[10],struct element_listy *nowy,struct element_listy**poczatek);
void sortimie(struct element_listy ** poczatek);
void sortnazwisko(struct element_listy ** poczatek);
void sortgrupa(struct element_listy ** poczatek);
void usunarg(struct element_listy **poczatek);
void poisk(struct element_listy *poczatek);
struct element_listy **wczyt(struct element_listy **poczatek);
struct element_listy *dodawanie();

int main(void){
	struct element_listy *temp,**poczatek=NULL;
    char bufor[40];
    char po[30];
    char co[30];
    poczatek=wczyt(poczatek);
	if(poczatek==0) return 0;
	else
        while(1){
            system("cls");
            printf(">>Ksiazka telefoniczna<<\n Dostepne opcje:\n1.Wyswietl (wyswietla liste)\n2.Sortuj (posortowac)\n3.Dodaj (dodac kontakt)\n4.Wyszukaj (wyszukac kontakt)\n5.Usun (usunac kontakt)\n6.Duplikaty (usunac duplikaty)\n\n");
            gets(bufor);
            if(strstr(bufor,"2")){
                printf("\nDostepne opcje sortowania:\n\na:Imie\nb:Nazwisko\nc:Grupa\n\n");
                gets(po);
                if(strstr(po,"c")){
                    sortgrupa(poczatek);
                }
                if(strstr(po,"b")){
                    sortnazwisko(poczatek);
                }
                if(strstr(po,"a")){
                    sortimie(poczatek);
                }
                printf("Posortowane.\n");
                getchar();
            }
            if(strstr(bufor,"0")){
                printf("Zamykam ksiazke.\n");
                getchar();
                break;
            }
            if(strstr(bufor,"5")){
                printf("\n");
                usunarg(poczatek);
                printf("Kontakt usuniety.\n");
                getchar();
            }
            if(strstr(bufor,"1")){
                printf("\n");
                wyswietl(poczatek);
                getchar();
            }
            if(strstr(bufor,"3")){
                temp=dodawanie();
                printf("Czy lista byla sortowana?\n Jesli tak, to napisz po czym(Imie, Nazwisko, Grupa), jezeli nie, napisz (nic)\n");
                gets(co);
                newplace(co,temp,poczatek);
                getchar();
            }
            if(strstr(bufor,"4")){
                poisk(*poczatek);
                getchar();
            }
            if(strstr(bufor,"6")){
                duplikat;
                printf("Duplikaty usuniete\n");
                getchar();
            }
        }
}

struct element_listy** wczyt(struct element_listy **poczatek)
{
	FILE *f=NULL;
	char plik[40];
	char otworz[50]="D:\\Studia\\III sem\\Informatyka II\\Ksiazka\\";
	kontakt *temp,*pomoc,**pamiec;
	char Sprawdz[50+1];
	char *sub;
	pamiec=(kontakt**)malloc(sizeof(kontakt*));
	*pamiec=(kontakt*)malloc(sizeof(kontakt));//Na koncu rozciagnaж tablice
	*pamiec=NULL;
	while(1)
	{
		gets(plik);
		strcat(plik,"tel.txt");
		strcat(otworz,plik);
		f= fopen(otworz,"r");
		if(strstr(plik,"Wyjdz"))
			return 0;
		if(f==NULL)
		{
			printf("Spokojnie, sprobuj jeszcze raz\n Jezeli jednak nie chcesz nic robic uzyj komendy 'Wyjdz'\n");
		}


		if(f!=NULL)
			break;
	}

		while(fscanf(f,"%s",Sprawdz)!=EOF)
		{
			//tworzenie nowego elementu
		temp=(struct element_listy*)malloc(sizeof(struct element_listy));
		temp->nastepny=NULL;
		temp->poprzedni=NULL;
		sub=strtok(Sprawdz,";");
		//odczyt imienia
		if(sub!=NULL)
		{
		strcpy(temp->dane.imie,sub);
		sub=strtok(NULL,";");
		strcpy(temp->dane.nazwisko,sub);
			sub=strtok(NULL,";");
		strcpy(temp->dane.numer,sub);
			sub=strtok(NULL,";");
		strcpy(temp->dane.grupa,sub);
			sub=strtok(NULL,";");
			if(sub!=NULL)
			{
				printf("Zle napisana lista!\n");
			}

		}
		if(*pamiec==NULL)
			*pamiec=temp;
		else
		{
			pomoc=*pamiec;
			while(pomoc->nastepny!=NULL)
				pomoc=pomoc->nastepny;
			temp->poprzedni=pomoc;
			pomoc->nastepny=temp;
		}
		}

	poczatek=pamiec;
	return poczatek;
}

void wyswietl(struct element_listy **poczatek){
	struct element_listy *nowy=*poczatek;
	if(*poczatek==NULL){
		printf("Zadna lista nie zostala wczytana.\n");
	}
	else{
        while(nowy!=NULL){
            printf("%s %s %s %s\n",nowy->dane.imie,nowy->dane.nazwisko,nowy->dane.numer,nowy->dane.grupa);
            nowy=nowy->nastepny;
        }
    }
	getchar();
}

void sortimie(struct element_listy ** poczatek){
	struct element_listy *nowy=NULL;
	struct element_listy *pomoc=(struct element_listy*)malloc(sizeof(struct element_listy *));
	struct element_listy *temp;
	struct element_listy **Zastep=(struct element_listy**)malloc(sizeof(struct element_listy *));
	Zastep=poczatek;
	pomoc=NULL;
	while(*Zastep!=NULL){
		temp=(kontakt*)malloc(sizeof(kontakt));
		strcpy(temp->dane.imie,(*poczatek)->dane.imie);
		strcpy(temp->dane.nazwisko,(*poczatek)->dane.nazwisko);
		strcpy(temp->dane.numer,(*poczatek)->dane.numer);
		strcpy(temp->dane.grupa,(*poczatek)->dane.grupa);
		temp->nastepny=0;
		temp->poprzedni=0;
		if(nowy==NULL){
			nowy=temp;
		}
		else if(strcmp(nowy->dane.imie,temp->dane.imie)>0){
		temp->nastepny=nowy;
		nowy->poprzedni=temp;
		nowy=temp;
        }
        else{
		pomoc=nowy;
		while(pomoc->nastepny!=NULL&&strcmp(pomoc->nastepny->dane.imie,temp->dane.imie)<0)
			pomoc=pomoc->nastepny;
		temp->poprzedni=pomoc;
		temp->nastepny=pomoc->nastepny;
		if(pomoc->nastepny!=NULL)
			pomoc->nastepny->poprzedni=temp;
		pomoc->nastepny=temp;
        }
        pomoc=*Zastep;
        *Zastep=(*Zastep)->nastepny;
        free(pomoc);
    }
	*poczatek=nowy;
}

void sortnazwisko(struct element_listy **poczatek){
	struct element_listy *nowy=NULL;
	struct element_listy *pomoc=(struct element_listy*)malloc(sizeof(struct element_listy *));
	struct element_listy *temp;
	struct element_listy **Zastep=(struct element_listy**)malloc(sizeof(struct element_listy *));
	Zastep=poczatek;
	pomoc=NULL;
	while(*Zastep!=NULL){
		temp=(kontakt*)malloc(sizeof(kontakt));
		strcpy(temp->dane.imie,(*poczatek)->dane.imie);
		strcpy(temp->dane.nazwisko,(*poczatek)->dane.nazwisko);
		strcpy(temp->dane.numer,(*poczatek)->dane.numer);
		strcpy(temp->dane.grupa,(*poczatek)->dane.grupa);
		temp->nastepny=0;
		temp->poprzedni=0;

		if(nowy==NULL){
			nowy=temp;
		}
		else if(strcmp(nowy->dane.nazwisko,temp->dane.nazwisko)>0){
		temp->nastepny=nowy;
		nowy->poprzedni=temp;
		nowy=temp;
        }
        else{
		pomoc=nowy;
		while(pomoc->nastepny!=NULL&&strcmp(pomoc->nastepny->dane.nazwisko,temp->dane.nazwisko)<0) pomoc=pomoc->nastepny;
		temp->poprzedni=pomoc;
		temp->nastepny=pomoc->nastepny;
		if(pomoc->nastepny!=NULL) pomoc->nastepny->poprzedni=temp;
		pomoc->nastepny=temp;
        }
        pomoc=*Zastep;
        *Zastep=(*Zastep)->nastepny;
        free(pomoc);
    }
	*poczatek=nowy;
}

void sortgrupa(struct element_listy **poczatek){
	struct element_listy *nowy=NULL;
	struct element_listy *pomoc=(struct element_listy*)malloc(sizeof(struct element_listy *));
	struct element_listy *temp;
	struct element_listy **Zastep=(struct element_listy**)malloc(sizeof(struct element_listy *));
	Zastep=poczatek;
	pomoc=NULL;
	while(*Zastep!=NULL){
		temp=(kontakt*)malloc(sizeof(kontakt));
		strcpy(temp->dane.imie,(*poczatek)->dane.imie);
		strcpy(temp->dane.nazwisko,(*poczatek)->dane.nazwisko);
		strcpy(temp->dane.numer,(*poczatek)->dane.numer);
		strcpy(temp->dane.grupa,(*poczatek)->dane.grupa);
		temp->nastepny=0;
		temp->poprzedni=0;

		if(nowy==NULL){
			nowy=temp;
		}
		else if(strcmp(nowy->dane.grupa,temp->dane.grupa)>0){
		temp->nastepny=nowy;
		nowy->poprzedni=temp;
		nowy=temp;
        }
        else{
		pomoc=nowy;
		while(pomoc->nastepny!=NULL&&strcmp(pomoc->nastepny->dane.grupa,temp->dane.grupa)<0)
			pomoc=pomoc->nastepny;
		temp->poprzedni=pomoc;
		temp->nastepny=pomoc->nastepny;
		if(pomoc->nastepny!=NULL)
			pomoc->nastepny->poprzedni=temp;
		pomoc->nastepny=temp;
        }
        pomoc=*Zastep;
        *Zastep=(*Zastep)->nastepny;
        free(pomoc);
    }
	*poczatek=nowy;
}

struct element_listy *dodawanie(){
	int i,c,n,j,z=0;
	char tab_imie[20];
	char tab_nazwisko[20];
	char tab_grupa[20];
	char tab_numer[20];
	struct element_listy *nowe=(struct element_listy*)malloc(sizeof(struct element_listy *));
	printf("Podaj imie:");
	gets(tab_imie);
	do{
		c=0;
        for(i=0;i<strlen(tab_imie);i++){
            if((63>=tab_imie[i]>=33)==1){
            printf("Samo imie bez niepotrzebnych znakow.\n Sprobuj jeszcze raz.\n");
            c++;
            break;
            }
        }
        if(c==0) break;
        else gets(tab_imie);
	}while(1);
	strcpy(nowe->dane.imie,tab_imie);
	printf("Podaj nazwisko:");
	gets(tab_nazwisko);
	do{
		n=0;
        for(i=0;i<strlen(tab_nazwisko);i++){
            if((63>=tab_nazwisko[i]>=33)==1){
                printf("Samo nazwisko bez niepotrzebnych znakow.\n Sprobuj jeszcze raz.\n");
                n++;
                break;
            }
        }
        if(n==0) break;
        else gets(tab_nazwisko);
	}while(1);
	strcpy(nowe->dane.nazwisko,tab_nazwisko);
	printf("Podaj grupe:");
	gets(tab_grupa);
	do{
		j=0;
        for(i=0;i<strlen(tab_grupa);i++){
            if((63>=tab_grupa[i]>=33)==1){
                printf("Sama nazwa grupy bez niepotrzebnych znakow.\n Sprobuj jeszcze raz.\n");
                j++;
                break;
            }
        }
        if(j==0) break;
        else gets(tab_grupa);
	}while(1);
	strcpy(nowe->dane.grupa,tab_grupa);
	while((strlen(tab_numer)!=9)&&z==0){
		z=0;
		printf("Podaj numer tej osoby:");
        gets(tab_numer);
        if(strlen(tab_numer)!=9)
            printf("Zla dlugosc numeru, powienien zawierac 9 cyfr.\n");
        for(i=0;i<strlen(tab_numer);i++){
            if((126>=tab_numer[i]>=58||47>=tab_numer[i]>=32)==1){
                printf("Sam numer bez niepotrzebnych znakow.\n Sprobuj jeszcze raz.\n");
                z++;
                break;
            }
        }
	}
	strcpy(nowe->dane.numer,tab_numer);
	nowe->nastepny=NULL;
	nowe->poprzedni=NULL;
	return nowe;
}

//Ustawianie dodanego elementu
void newplace(char co[10],struct element_listy *nowe,struct element_listy**poczatek){
	struct element_listy *pomoc,*temp;
    temp=NULL;
    pomoc=NULL;
	if(strstr(co,"nazwisko")){
		if(*poczatek==NULL)
            *poczatek=temp;
		else if(strcmp((*poczatek)->dane.nazwisko,temp->dane.nazwisko)>0){
			temp->nastepny=*poczatek;
			(*poczatek)->poprzedni=temp;
			*poczatek=temp;
		}
		else{
			pomoc=*poczatek;
			while ((pomoc->nastepny!=NULL)&&strcmp(pomoc->nastepny->dane.nazwisko,temp->dane.nazwisko)<0)
				pomoc=pomoc->nastepny;
			temp->poprzedni=pomoc;
			temp->nastepny=pomoc->nastepny;
			if(pomoc->nastepny!=NULL)
				pomoc->nastepny->poprzedni=temp;
			pomoc->nastepny=temp;

		}
	}
	if(strstr(co,"imie")){
		if(*poczatek==NULL)
			*poczatek=temp;
		else if(strcmp((*poczatek)->dane.imie,temp->dane.imie)>0){
			temp->nastepny=*poczatek;
			(*poczatek)->poprzedni=temp;
			*poczatek=temp;
		}
		else{
			pomoc=*poczatek;
			while ((pomoc->nastepny!=NULL)&&strcmp(pomoc->nastepny->dane.imie,temp->dane.imie)<0)
				pomoc=pomoc->nastepny;
			temp->poprzedni=pomoc;
			temp->nastepny=pomoc->nastepny;
			if(pomoc->nastepny!=NULL)
				pomoc->nastepny->poprzedni=temp;
			pomoc->nastepny=temp;
		}
	}
	if(strstr(co,"grupa")){
		if(*poczatek==NULL)
			*poczatek=temp;
		else if(strcmp((*poczatek)->dane.grupa,temp->dane.grupa)>0){
			temp->nastepny=*poczatek;
			(*poczatek)->poprzedni=temp;
			*poczatek=temp;
		}
		else{
			pomoc=*poczatek;
			while ((pomoc->nastepny!=NULL)&&strcmp(pomoc->nastepny->dane.grupa,temp->dane.grupa)<0)
				pomoc=pomoc->nastepny;
			temp->poprzedni=pomoc;
			temp->nastepny=pomoc->nastepny;
			if(pomoc->nastepny!=NULL)
				pomoc->nastepny->poprzedni=temp;
			pomoc->nastepny=temp;
		}
	}
	if(strstr(co,"nic")){
		if(*poczatek!=NULL){
			(*poczatek)->poprzedni=nowe;
			nowe->nastepny=*poczatek;
		}
	}
	*poczatek=nowe;
}

///Wyszukiwanie elementow
void poisk(struct element_listy *poczatek){
	struct element_listy *pomoc=(struct element_listy*)malloc(sizeof(struct element_listy *));
	struct element_listy *temp1=poczatek,*temp2=poczatek;
	char tab[20];//tablica znakow na wprowadzony fragment
	char tab2[20];
	printf("Podaj imie szukanego:\n");
	gets(tab);//wpisanie do tablicy fragmentu
	printf("Znalezione kontakty po imieniu.\n");
	while(temp1!=NULL){
		if(strstr(temp1->dane.imie,tab)){
			printf("%s %s %s %s\n",temp1->dane.imie,temp1->dane.nazwisko,temp1->dane.numer,temp1->dane.grupa);
		}
		temp1=temp1->nastepny;
	}
	printf("Podaj nazwisko dla lepszej dokladnosci\n");
	gets(tab2);
	printf("Szukany kontakt\n");
	while(temp2!=NULL){
		if(strstr(temp2->dane.imie,tab)&&strstr(temp2->dane.nazwisko,tab2)){
			printf("%s %s %s %s\n",temp2->dane.imie,temp2->dane.nazwisko,temp2->dane.numer,temp2->dane.grupa);
		}
		temp2=temp2->nastepny;
	}
	temp1=NULL;
	temp2=NULL;
	free(temp1);
	free(temp2);
}

//Szukanie jednego elementu
struct element_listy *poisk1(struct element_listy *poczatek,char *imie,char*nazwisko){
	struct element_listy *pomoc;
	pomoc=poczatek;
	while(pomoc!=NULL&&strstr(pomoc->dane.imie,imie)&&strstr(pomoc->dane.nazwisko,nazwisko))
		pomoc=pomoc->nastepny;
	return pomoc;
}

//Usuwanie kontaktu
void usunarg(struct element_listy **poczatek){
	struct element_listy *temp,*pomoc;
	char nazwisko[30];
	char imie[30];
	printf("Podaj imie:");
	gets(imie);
	printf("Sprecyzuj nazwiskiem:");
	gets(nazwisko);
	temp=poisk1(*poczatek,imie,nazwisko);
	if(temp==NULL)
		printf("Nie ma takiej osoby w kontaktach.\n");
	else{
		if(temp==*poczatek){
			*poczatek=(*poczatek)->nastepny;
			if(temp->dane.imie)
				*temp->dane.imie=NULL;
			if(temp->dane.nazwisko)
				*temp->dane.nazwisko=NULL;
			if(temp->dane.numer)
				*temp->dane.numer=NULL;
			if(temp->dane.grupa)
				*temp->dane.grupa=NULL;
			free(temp);
		}
		else{
			pomoc=*poczatek;
			while(strcmp(pomoc->nastepny->dane.nazwisko,temp->dane.nazwisko)!=0)
				pomoc=pomoc->nastepny;
			if(temp->nastepny!=NULL)
				pomoc->nastepny->poprzedni=temp->poprzedni;
			pomoc->nastepny=temp->nastepny;
			if(temp->dane.imie)
				*temp->dane.imie=NULL;
			if(temp->dane.nazwisko)
				*temp->dane.nazwisko=NULL;
			if(temp->dane.numer)
				*temp->dane.numer=NULL;
			if(temp->dane.grupa)
				*temp->dane.grupa=NULL;
			free(temp);
		}
	}
}

void duplikat(kontakt **poczatek){
	kontakt *temp,*pomoc,*pom;
	temp=*poczatek;
    while(temp!=NULL){
        pomoc=temp;
        while(pomoc->nastepny!=NULL){
            if(((strcmp(pomoc->nastepny->dane.nazwisko,temp->dane.nazwisko))==0)&&(strcmp(pomoc->nastepny->dane.imie,temp->dane.imie))==0){
                pom=pomoc->nastepny;
                pomoc->nastepny=pom->nastepny;
                if(pom->dane.imie)
                    *pom->dane.imie=NULL;
                if(pom->dane.nazwisko)
                    *pom->dane.nazwisko=NULL;
                if(pom->dane.numer)
                    *pom->dane.numer=NULL;
                if(pom->dane.grupa)
                    *pom->dane.grupa=NULL;
                free(pom);
            }
            else
                pomoc=pomoc->nastepny;
        }
        temp=temp->nastepny;
    }
}
