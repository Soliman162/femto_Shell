#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>

#define Inputs_SIZE		10

char * _argv_[10]  ; 
char Inputs[Inputs_SIZE][Inputs_SIZE]; 

/*====================================================================*/

static inline void RECIEVE_void_INPUTS(void)
{
	int i = 0, j=0, z=0;
	char Input_Char = '\0'; 

	/*recive inputs */
	while( ( Input_Char = getchar()) != '\n' )
	{
		if( Input_Char == ' ' )
		{
			_argv_[j++] = Inputs[i];
			i++;
			z=0;
		}
		else { Inputs[i][z++] = Input_Char; }
	}
	/*Store last input*/
	_argv_[j] =  Inputs[i];
}

/*====================================================================*/

static inline void Clear_void_Strings(void)
{
	int i = 0, j=0, z=0;

	/*Clear strings and variables*/
	for(i=0;_argv_[i] != NULL;i++)
	{
		_argv_[i] = NULL;
		for(j=0;Inputs[i][j] != '\0';j++)
		{
			Inputs[i][j] = '\0';
		}
	}
}

/*====================================================================*/

int main(void)
{
    pid_t PID = -1;
    int status = 0;
	
	do{
			printf("Welcome in my Shell > ");

			/**********************/
			RECIEVE_void_INPUTS();
			/*********************/

			/*check for the Recived inputs if it is empty*/
			if( Inputs[0][0] != '\0' )
			{
				/*Create the child process using fork*/
				PID = fork();
				
				/*The child will excute the command in argv */
				if (PID == 0){ execvp(_argv_[0],_argv_ ); }
				
				/*The parent process will wait for the termination of the child process*/
				else if (PID>0){ wait(&status); }

				/*********************/
				Clear_void_Strings();
				/*********************/

			}

	}/*check if it should Exit */
	while ( strcmp(Inputs[0], "Exit") );

	printf("good bye:)\n");

	return 0;
}