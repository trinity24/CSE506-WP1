#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char * concat(char *s1,char *s2)
{
	char *des =(char *)malloc(sizeof(char*)*(strlen(s1)+strlen(s2))+1);
	int l1=strlen(s1);
	int l2=strlen(s2);

	for(int i=0;i<strlen(s2);i++)
	{

		*(des+i)=*(s1+i);
	}
	printf("going on for secind string\n");
	for(int i=0;i<strlen(s2);i++)
	{
		//
		*(des+l1+i)=*(s2+i);
	}
	*(des+1+l1+l2)="\0";
	return des;
} 

int main()
{
	char *s="ls &";
	char *s1="sha sha";
	char *s2=concat(s,s1);
	printf("%s \n",s2 );
	
	return 0;
}