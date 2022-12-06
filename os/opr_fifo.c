#include <stdio.h>

#include <stdlib.h>

int RefString[15], PT[3];
void Accept()
{
  int i;
  printf("Enter Reference String: \n");
  for (i = 0; i < 15; i++)
  {
    printf("[%d]=", i);
    scanf("%d", &RefString[i]);
  }
}

int Search(int s)
{
  int i;
  for (i = 0; i < 3; i++)
    if (PT[i] == s)
      return (i);
  return (-1);
}

void FIFO()
{
  int i, j, k = 0, Faults = 0;
  for (i = 0; i < 15; i++)
  {

    printf("%2d", RefString[i]);
    if (Search(RefString[i]) == -1)
    {
      PT[k] = RefString[i];
      for (j = 0; j < 3; j++)
      {

        if (PT[j])
        {

          printf("%2d", PT[j]);
        }
      }
      printf("\n");
      Faults++;
      k = (k + 1) % 3;
    }
    printf("\n");
  }
  // gotoxy(10,24);
  printf("Total page Faults:%d", Faults);
}

int main()
{
  Accept();
  system("clear");
  FIFO();
  return 0;
}
