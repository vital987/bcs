#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>
int main()
{
pid_t pid;	
pid=fork();										
if(pid==0)
{
   printf("\n I am child process,id=%d",getpid());
   printf("\n priority :%d,id=%d\n",nice(-7),getpid());
 }
 else
   {
   printf("\n I am parent process,id=%d",getpid());
   nice(1); 
   printf("\n priority:%d,id=%d\n",nice(15),getpid());
   }
   return 0;
   }
