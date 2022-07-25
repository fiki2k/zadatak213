// Program treba izracunat koliko godina korisnik ima ako unese datum rodenja.

#include <stdio.h>
#include <time.h>
 
/*Provjer je li godina prijestupna.*/
int prijestupna(int godina, int mjesec) 
{
    int flag = 0;
    if (godina % 100 == 0) 
    {
            if (godina % 400 == 0) 
            {
                    if (mjesec == 2) 
                    {
                            flag = 1;
                    }
            }
    } 
    else if (godina % 4 == 0) 
    {
            if (mjesec == 2) 
            {
                    flag = 1;
            }
    }
    return (flag);
}
 
 
int main()
{
 
    int DaniUmjesecu[] = {31, 28, 31, 30, 31, 30,
                       31, 31, 30, 31, 30, 31};
    int dan, mjesec, godina;
    char dob[100];
    time_t ts;
    struct tm *ct;
 
 
    printf("Unesi datum rodenja (DD/MM/GGGG): ");
    scanf("%d/%d/%d",&dan,&mjesec, &godina);
 
    /*dobij sadasnje vrijeme.*/
    ts = time(NULL);
    ct = localtime(&ts);
 
    printf("Danasnji datum : %d/%d/%d\n",
            ct->tm_mday, ct->tm_mon + 1, ct->tm_year + 1900);
 
    dan = DaniUmjesecu[mjesec - 1] - dan + 1;
 

    if (prijestupna(godina, mjesec)) 
    {
            dan = dan + 1;
    }
 

    dan = dan + ct->tm_mday;
    mjesec = (12 - mjesec) + (ct->tm_mon);
    godina = (ct->tm_year + 1900) - godina - 1;
 
    /* provjera za prijestupnu veljaca - 29 dana */
    if (prijestupna((ct->tm_year + 1900), (ct->tm_mon + 1))) 
    {
            if (dan >= (DaniUmjesecu[ct->tm_mon] + 1)) 
            {
                    dan = dan - (DaniUmjesecu[ct->tm_mon] + 1);
                    mjesec = mjesec + 1;
            }
    } 
    else if (dan >= DaniUmjesecu[ct->tm_mon]) 
    {
            dan = dan - (DaniUmjesecu[ct->tm_mon]);
            mjesec = mjesec + 1;
    }
 
    if (mjesec >= 12) 
    {
            godina = godina + 1;
            mjesec = mjesec - 12;
    }
 
    /* ispis godina */
    printf("\n## Star si %d godina %d mjeseci i %d dana. ##\n", godina, mjesec, dan);
 
    return 0;
}
