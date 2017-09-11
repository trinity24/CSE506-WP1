#include <stdio.h>
#include <unistd.h>
#include <string.h>
int main()
{	
	
	char *readline;
	int status;
	size_t readlineSize =0;
	pid_t pid;
	char *command;char *cat="cat",*path;
	int fd;
	char *buffer;
	getline(&readline, &readlineSize, stdin);

	command=strtok(readline," ");
	if(strcmp(command,cat)==0)
	{
		//if your command is cat then
	
		path=strtok(NULL," ");
		printf("%s\n",path );

		fd=open(path);
		
		while(fd!=EOF)
		{
			printf("%c\n", *fd);

		}
		
	}


	return 0;
 	

}