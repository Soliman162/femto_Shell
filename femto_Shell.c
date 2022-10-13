#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>

#define Inputs_SIZE			10	
#define SET_ENV_VAR_NUM		10

char * _argv_[10]  ; 
char Inputs[Inputs_SIZE][Inputs_SIZE]; 
//char *Set_env[SET_ENV_VAR_NUM][2];

char *Set_env_var[10];
char *set_env_value[10];

/**
 * @brief 
 * 
 * This function recieve inputs from standard input and store it in ( _argv_  &  Inputs ) 
 * 
 */
static inline void RECIEVE_void_INPUTS(void)
{
	int i = 0, j=0, z=0;
	char Input_Char = '\0'; 

	/*receive inputs */
	while( ( Input_Char = getchar()) != '\n' )
	{
		if( (Input_Char == ' ') || (Input_Char == '=') )
		{
			_argv_[j++] = Inputs[i];

			if(  Input_Char == '=' ) 
			{ 
				Inputs[++i][0] = '='; 
			} 
			i++;
			z=0;
		}
		else { Inputs[i][z++] = Input_Char; }
	}
	/*Store last input*/
	_argv_[j] = Inputs[i];
}

/**
 * @brief 
 * 
 * This function clear ( _argv_  &  Inputs ) by set all thier elements to null
 * 
 */
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

int main(void)
{
    pid_t PID = -1;
    int status = 0;
	int Set_env_Iterator_1 = 0;
	int Set_env_Iterator_2 = 0;
	
	do{
			printf("Welcome in my Shell > ");

			/*********************/
			Clear_void_Strings();
			/*********************/

			/*********************/
			RECIEVE_void_INPUTS();
			/*********************/

			/*check for the Recived inputs if it is empty*/
			if( Inputs[0][0] != '\0' )
			{
				/*Create the child process using fork*/
				PID = fork();
				
				/*The child will excute the command in argv */
				if (PID == 0)
				{ 
					if( Inputs[1][0] == '=' )
					{
						Set_env_var[Set_env_Iterator_1] = _argv_[0]; 
						set_env_value[Set_env_Iterator_1] = _argv_[1];

						if( setenv( _argv_[0]  , _argv_[1] , 1 ) != -1 )
						{
							printf("setenv success \n");
						}
						Set_env_Iterator_1++;
					}
					else
					{
						execvp( _argv_[0] , _argv_ ); 
					}
				}
				/*The parent process will wait for the termination of the child process*/
				else if (PID>0){ wait(&status); }
			}

	}/*check if it should Exit */
	while ( strcmp(Inputs[0], "Exit") );

	printf("good bye:)\n");

	return 0;
}