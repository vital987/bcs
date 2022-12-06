#include <stdio.h>
#include <stdlib.h>
int count(char *fname);
int print(char *fname);
int top(char *fname, int c);
int bottom(char *fname, int c, int total);
int total, c, current;

void main(int argc, char *argv[])
{
  char *p;
  if (argc != 4)
    printf("invalid number of arguments");
  if (*argv[2] == '+' || *argv[2] == '-')
  {
    total = count(argv[3]);
    p = argv[2];
    p++;
    c = atoi(p);
    if (c > total)
      printf("invalid line count\n");
    if (*argv[2] == '+')
      top(argv[3], c);
    else if (*argv[2] == '-')
      bottom(argv[3], c, total);
    else
      print(argv[3]);
  }
}

int count(char *fname)
{
  int total, ch;
  FILE *fp;
  fp = fopen(fname, "r");
  if (fp == NULL)
  {
    printf("\nunable to open file");
    return (-1);
  }
  total = 0;
  ch = fgetc(fp);
  while (ch != EOF)
  {
    if (ch == 10)
      total++;
    ch = fgetc(fp);
  }
  total++;
  fclose(fp);
  return (total);
}

int print(char *fname)
{
  int ch;
  FILE *fp;
  fp = fopen(fname, "r");
  ch = fgetc(fp);
  while (ch != EOF)
  {
    printf("%c", ch);
    ch = fgetc(fp);
  }
  fclose(fp);
}

int top(char *fname, int c)
{
  int ch;
  FILE *fp;
  current = 0;
  fp = fopen(fname, "r");
  ch = fgetc(fp);
  while (current < c)
  {
    printf("%c", ch);
    if (ch == 10)
      current++;
    ch = fgetc(fp);
  }
  fclose(fp);
}

int bottom(char *fname, int c, int total)
{
  int current;
  int ch;
  FILE *fp;
  current = 0;
  fp = fopen(fname, "r");
  ch = fgetc(fp);
  while (1)
  {
    if (ch == 10)
      current++;
    if (current >= total - c)
      break;
    ch = fgetc(fp);
  }
  ch = fgetc(fp);
  while (ch != EOF)
  {
    printf("%c", ch);
    ch = fgetc(fp);
  }
  fclose(fp);
}
