#include <stdio.h>
#include <stdlib.h>

void sort_at(int *id, int *at, int *bt, int n)
{
    int tmp;
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (at[i] > at[j])
            {
                tmp = id[i];
                id[i] = id[j];
                id[j] = tmp;

                tmp = at[i];
                at[i] = at[j];
                at[j] = tmp;

                tmp = bt[i];
                bt[i] = bt[j];
                bt[j] = tmp;
            }
        }
    }
}

void find_stft(int *at, int *st, int *ft, int *bt, int *stft, int n)
{
    stft[0] = at[0];
    for (int i = 1; i < n + 1; i++)
    {
        stft[i] = stft[i - 1] + bt[i - 1];
    }
    for (int i = 0; i < n; i++)
    {
        st[i] = stft[i];
        ft[i] = stft[i + 1];
    }
}

void find_wttt(int *at, int *st, int *ft, int *wt, int *tt, int n)
{
    for (int i = 0; i < n; i++)
    {
        wt[i] = st[i] - at[i];
        tt[i] = ft[i] - at[i];
    }
}

void gantter(int *id, int *stft, int n)
{
    for (int i = 0; i < n; i++)
        printf("---------");
    printf("\n|   ");
    for (int i = 0; i < n; i++)
    {
        printf("P%d  |   ", id[i]);
    }
    printf("\n");
    for (int i = 0; i < n; i++)
        printf("---------");
    printf("\n");
    for (int i = 0; i < n + 1; i++)
        printf("%d\t", stft[i]);
    printf("\n");
}

int main(int argc, char *argv[])
{
    int n;
    ; // Number of processes
    printf("Number of Processes: ");
    scanf("%d", &n);
    int id[n], at[n], bt[n], wt[n], tt[n], st[n], ft[n], stft[n + 1];
    float wtavg, ttavg;
    for (int i = 0; i < n; i++)
    {
        printf("Process %d:\n", i);
        id[i] = i;
        printf("Arrival Time: ");
        scanf("%d", &at[i]);
        printf("Burst Time: ");
        scanf("%d", &bt[i]);
        printf("\n");
    }
    sort_at(id, at, bt, n);
    find_stft(at, st, ft, bt, stft, n);
    find_wttt(at, st, ft, wt, tt, n);
    printf("\nTABLE\nID\tAT\tBT\tST\tFT\tWT\tTT\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d\t%d\t%d\t%d\t%d\t%d\t%d\n", id[i], at[i], bt[i], st[i], ft[i], wt[i], tt[i]);
    }
    for (int i = 0; i < n; i++)
    {
        wtavg += wt[i];
        ttavg += tt[i];
    }
    wtavg /= n;
    ttavg /= n;
    printf("\nAVERAGES\nWaiting Time: %.2f\nTurnaround Time: %.2f\n", wtavg, ttavg);
    printf("\nGANTT CHART\n");
    gantter(id, stft, n);
    return 0;
}
