
#include <stdio.h>

int main()
{
	char * tokens[50];
	int i=0;
	char *command;
	size_t commandSize=0;
	getline(&command,&commandSize,stdin);
	for(i=0;i<50;i++)
	{
		
	}


	size_t n = 0;

	for (char * p = strtok(line, " "); p; p = strtok(NULL, " "))
	{
    	if (n >= 50)
    	{
        		// maximum number of storable tokens exceeded
        	break;
    	}
    	tokens[n++] = p;
	}

	for (size_t i = 0; i != n; ++i)
	{
    	 printf("Token %zu is '%s'.\n", i, tokens[i]);
	}
}