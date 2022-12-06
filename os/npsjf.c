#include <stdio.h>
void main()
{
   int i, j, temp, btemp, ptemp, at[6], bt[6], wt[6], tt[6], sum = 0, num, proc[6];
   float avrg, avg;
   printf("Enter the number of processes:");
   scanf("%d", &num);
   for (i = 0; i < num; i++)
   {
      printf("\nEnter the process number:");
      scanf("%d", &proc[i]);
      printf("\nEnter the process arrival time:");
      scanf("%d", &at[i]);
      printf("\nEnter the process burst time:");
      scanf("%d", &bt[i]);
   }
   for (i = 0; i < num; i++)
   {
      if (at[i] == 0)
      {
         temp = at[0];
         at[0] = at[i];
         at[i] = temp;
         btemp = bt[0];
         bt[0] = bt[i];
         bt[i] = btemp;
         temp = proc[0];
         proc[0] = proc[i];
         proc[i] = temp;
      }
   }
   for (i = 1; i < num; i++)
   {
      for (j = i + 1; j < num; j++)
      {
         if (bt[i] > bt[j])
         {
            temp = at[i];
            at[i] = at[j];
            at[j] = temp;
            btemp = bt[i];
            bt[i] = bt[j];
            bt[j] = btemp;
            temp = proc[i];
            proc[i] = proc[j];
            proc[j] = temp;
         }
      }
   }
   for (i = 1; i < num; i++)
   {
      for (j = i + 1; j < num; j++)
      {
         if (bt[i] == bt[j])
         {
            if (at[i] > at[j])
            {
               temp = at[i];
               at[i] = at[j];
               at[j] = temp;
               btemp = bt[i];
               bt[i] = bt[j];
               bt[j] = btemp;
               temp = proc[i];
               proc[i] = proc[j];
               proc[j] = temp;
            }
         }
      }
   }

   printf("\nAfter sorting on arrival time:\n");
   printf("Process\tArrivalTime\tBurst Time\n");
   for (i = 0; i < num; i++)
   {
      printf("\nP%d\t", proc[i]);
      printf("%d\t", at[i]);
      printf("%d\t", bt[i]);
   }
   wt[0] = 0;
   for (i = 0; i < num; i++)
   {
      wt[i + 1] = wt[i] + bt[i];
      sum = sum + (wt[i] - at[i]);
   }
   wt[num] = wt[num - 1] + bt[num - 1];
   printf("\nThe Sum Waiting Time Is:%d", sum);
   avrg = (float)sum / (float)num;
   printf("\nThe Average Wating Time Is:%f", avrg);
   sum = 0;
   for (i = 0; i < num; i++)
   {
      tt[i] = wt[i + 1] - at[i];
      sum = sum + tt[i];
   }
   printf("\nThe Sum Of Turnaround Time Is:%d", sum);
   avg = (float)sum / (float)num;
   printf("\nThe Average Turnaround Time Is:%f", avg);
   printf("\nGANTT CHART\n");
   printf("\n--------------------------------------------------------\n");
   for (i = 0; i < num; i++)
   {
      printf("|P%d\t", proc[i]);
   }
   printf("\n---------------------------------------------------------\n");
   for (i = 0; i <= num; i++)
   {
      printf("%d\t", wt[i]);
   }
}
