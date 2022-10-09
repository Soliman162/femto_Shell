#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>

#define STRING_COMMAND_SIZE		10
#define ENTER_KEY				10



int main(void)
{
    pid_t PID = -1;
    int status = 0;
	int i = 0, j=0;

	char * string_args[10]  ;
	char string_command[STRING_COMMAND_SIZE][STRING_COMMAND_SIZE]  ;

	char Input_Char = '\0'; 
	
/*===============================================================================================*/
	do{
		printf("Welcome in my Shell > ");

		do{
			if( Input_Char == ' ' )
			{
				string_args[j++] = string_command;
				//printf("%s",string_args[j-1]);
				//string_args[j] = NULL;

				for(i=0;i<STRING_COMMAND_SIZE;i++){string_command[i] = '\0';}

				i=0;
			}
			else
			{
				string_command[i++] = Input_Char;
			}

		}while( ( c = getchar()) != '\n' );

		//printf("%s\n",string_command);

		if( string_command[0] != '\0' )
		{

			PID = fork();

			if (PID == 0) 
			{
				//printf("string_args[0] = %s\n",string_args[0]);
				execvp(string_args[0],string_args );
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
		
	}
	while ( strcmp(string_command, "Exit") );
/*===============================================================================================*/

	printf("good bye:)\n");

	return 0;
}