#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>
int main()
{ 
int pid;
pid=getpid();
printf("current process id:%d",pid);
printf("\n[forking child process...]");
pid=fork();
if(pid<0)
  printf("\nprocess cant be created");
else if(pid==0)
 {
   printf("\n child process is sleeping...");
   sleep(5);
   printf("\n orphan child's parent id:%d",getpid());
   }
else
   printf("\nparent process is completed");
 return 0;
 }
  
