#include "stdio.h"
#include "string.h"

static inline void Recieve_voidString( char * Copy_ptru8String )
{

        scanf("%s",Copy_ptru8String);

}


int main(void)
{
	char string[] = "init string" ;
	

	do{

		printf("\nwelcome in my Shell > ");
		Recieve_voidString(string);
		printf("You enterd %s\n", string);

	}while( strcmp(string,"Exit") );
	
	printf("good bye:)\n");

	return 0;
}


