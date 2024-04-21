#include <stdio.h>
#include <string.h>
#include <stdbool.h>

bool only_stars(char* s){										
    int i;

    for(i=0;i<strlen(s);i++)
        if (s[i]!='*')
            return false;

    return true;
}

bool match(char* wzorzec, char* lancuch){						
    int wzorzec_length=strlen(wzorzec);							
    int lancuch_length=strlen(lancuch);						

    if (wzorzec_length==0 && lancuch_length==0)
        return true;

    if (wzorzec_length==0 && lancuch_length>0)
        return false;											

    if (only_stars(wzorzec))
        return true;

    if (lancuch_length==0)
        return false;

    if (wzorzec[0]!='*'){												
        if (wzorzec[0]==lancuch[0] || wzorzec[0]=='?'){					
            char s1[wzorzec_length];
            char s2[lancuch_length];
            int i;

            for (i=1;i<wzorzec_length;i++)								
                s1[i-1]=wzorzec[i];										
            for (i=1;i<lancuch_length;i++)								
                s2[i-1]=lancuch[i];										
			
            s1[wzorzec_length-1]='\0';
            s2[lancuch_length-1]='\0';

            return match(s1,s2);										
        }
        else
            return false;
    }else{																
        bool b1;
        bool b2;
        int i;

        char s1[wzorzec_length];
        for (i=1;i<wzorzec_length;i++)									 
            s1[i-1]=wzorzec[i];											
        s1[wzorzec_length-1]='\0';

        char s2[lancuch_length];
        for (i=1;i<lancuch_length;i++)									
            s2[i-1]=lancuch[i];											
        s2[lancuch_length-1]='\0';

        b1=match(s1,lancuch);											
        b2=match(wzorzec,s2);											

        if (b1||b2)														
            return true;												
        else
            return false;
    }

}
int main(){
    char s1[50];
    char s2[50];

    while (1){
        scanf("%s",s1);
        scanf("%s",s2);
        if (match(s1,s2))
            printf("Tak.\n\n");
        else
            printf("Nie.\n\n");
    }
    return 0;
}

