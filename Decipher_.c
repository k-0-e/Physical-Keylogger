#include <stdio.h>
#include <stdlib.h>

int main()
{
    char read[1000];
    char name[30];
    char capture;
    int a;
    FILE *ff,*fp;

    printf("\n\t\t<<<<<<<<<<< Deciphering The Caesar Cipher>>>>>>>>>>");
    printf("\nEnter File  To Decipher :");
    gets(name);

    ff=fopen(name,"r");
    fp=fopen("DeCipher.txt","w");
    if(ff==0 && fp==0 )
    {
        printf("\nFile Error !");
        exit(0);
    }

    while(!feof(ff))
    {
        fgets(read,1000,ff);
        for(a=0;read[a]!='\0';a++)
    {
        capture=read[a];
        read[a]=toascii(capture)-3;
    }
    fprintf(fp,read);
    printf("\n%s",read);
    }
    fclose(ff);
    fclose(fp);

    return main();
}

