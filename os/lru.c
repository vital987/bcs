#include<stdio.h>
#define MAX 20
int fr[MAX],r[MAX],me[MAX][MAX],f,s,m,n,t[MAX];
void accept()
{
int i;
printf("enter no of frames:");
scanf("%d",&n);
printf("enter length of reference string:");
scanf("%d",&m);
printf("enter string elements:\n");
for(i=0;i<m;i++)
{
  printf("[%d]=",i );
  scanf("%d",&r[i]);
 }
}
void display()
{
int i,j;
for(i=0;i<m;i++)
   printf("%3d",r[i]);
 printf("\n");
for(i=0;i<n;i++)
 {
   for(j=0;j<m;j++)
   {
     if(me[i][j])
       printf("%3d",me[i][j]);
     else
       printf("    ");
   }
   printf("\n");
 }
 printf("total page faults:%d",f);
}
int search(int p)
{ 
int i;
for(i=0;i<n;i++)
  if(fr[i]==p)
    return 1;
return -1;
}
int get()
{
int i,mi,min=9999;
for(i=0;i<n;i++)
  if(t[i]<min)
  {
     min=t[i];
     mi=i;
   }
 return mi;
}
void lru()
{
int i,j,k;
for(i=0;i<m && s<n;i++)
{
  k=search(r[i]);
  if(k==-1)
  {
    fr[s]=r[i];
    t[s]=i;
    f++;
    s++;
    for(j=0;j<n;j++)
      me[j][i]=fr[j]; 
   }
  else
    t[k]=i;
 }
 for(i=0;i<m;i++)
 {
  k=search(r[i]);
  if(k==-1)
  {
    s=get();
    fr[s]=r[i];
    t[s]=i;
    f++;
    for(j=0;j<n;j++)
      me[j][i]=fr[j];
   }
   else
     t[k]=i;
  }
  }
  int main()
  {
  accept();
  lru();
  display();
  return 0;
  }
 
