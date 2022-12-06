#include <stdio.h>
#include <string.h>
int count(char fname[], char option);
int main(int argc, char *argv[])
{
        char fname[20];
        char option;
        if (argc != 4)
        {
                printf("invalid no of arguments");
        }
        option = *argv[2];
        strcpy(fname, argv[3]);
        count(fname, option);
}
int count(char fname[], char option)
{
        long ccnt, wcnt, lcnt;
        FILE *fp;
        long lflag, wflag;
        int ch;
        fp = fopen(fname, "r");
        if (fp == NULL)
        {
                printf("\nfile does not exist");
        }
        ccnt = wcnt = lcnt = 0;
        lflag = wflag = 1;
        ch = fgetc(fp);
        while (ch != EOF)
        {
                ccnt++;
                if (ch == ' ' || ch == '\t')
                {
                        lflag = 0;
                        if (wflag == 0)
                        {
                                wcnt++;
                                wflag = 1;
                        }
                }
                else if (ch == 10) // enter
                {
                        ccnt++;
                        lcnt++;
                        lflag = 1;
                        if (wflag == 0)
                        {
                                wcnt++;
                                wflag = 1;
                        }
                }
                else
                {
                        wflag = 0;
                        lflag = 0;
                }
                ch = fgetc(fp);
        }
        if (wflag == 0)
                wcnt++;
        if (lflag == 0)
                lcnt++;
        switch (option)
        {
        case 'c':
                printf("\nchar count=%ld\n", ccnt);
                break;
        case 'w':
                printf("\nword count=%ld\n", wcnt);
                break;
        case 'l':
                printf("\nline count=%ld\n", lcnt);
        }
}
