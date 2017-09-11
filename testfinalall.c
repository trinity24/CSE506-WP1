#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>	
char* getc1()
{
	char *c;
	c=(malloc(sizeof(char)));
	read(0,c,1);
	if(*c!='\0'){
		printf("%c\n",*c );
		return c;
	}
	else
		return NULL;
		
}

int getline1(char *readline,int *readlineSize,FILE *stream)
{
	char *c=getc1();int i=0;
	while(getc1())
	{
		readline=(char*)(malloc(sizeof(char)));
		readline=c;
		readline++;i++;
	}
	return i;

}
/*
int main()
{
	
	char *readline=NULL;
	int readlineSize=0;
	getline1(readline,&readlineSize,stdin);
	printf("%s is the readline\n", readline);
	return 0;
}
*/
int main()
{
	char *c=getc1();
	printf("%s\n", c);
	char *readline=NULL;
	int readlineSize=0;
	getline1(readline,&readlineSize,stdin);
	printf("%s is the readline\n", readline);
	return 0;	
}