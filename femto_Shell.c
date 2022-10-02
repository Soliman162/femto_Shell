#include "stdio.h"
#include "string.h"
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>


int main(void)
{
    char string[] = "init string";
    pid_t PID = 0;

    int status = 0;

    char *s1[] = { NULL };
    char *s2[] = { NULL };
 
	do{

		printf("\nWelcome in my Shell > ");
		scanf("%s",string);
		printf("You enterd %s\n", string);

		PID = fork();

		if (PID == 0) 
		{
			execve(string, s1, s2);
		}
		else if (PID < 0) 
		{
			printf("fork faild\n");
		}
		else if (PID>0)
		{
			wait(&status);
		}
	}
	while (strcmp(string, "Exit"));

	printf("good bye:)\n");

	return 0;
}




/*


		if( PID == 0 )
		{
			printf("\nWelcome in my Shell > ");
			Recieve_voidString(string);
			printf("You enterd %s\n", string);
			execve(string, s1, s2);

		}else if(PID<0)
		{
			printf("fork faild\n");
		}
*/
