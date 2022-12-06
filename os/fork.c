#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
int main()
{
	int pid = fork();
	if (pid == 0)
		printf("I am child process.\nChild PID: %d\n\n", getpid());
	else if (pid > 0)
                printf("I am parent process.\nParent PID: %d\n\n", getpid());
	else
		printf("Failed to create child process.\n");
	return 0;
}
