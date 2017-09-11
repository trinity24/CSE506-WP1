#include <stdio.h>
#include <stdlib.h>
/*

 char* lsh_read_line(void)
{
  char *line = NULL;
  ssize_t bufsize = 0; // have getline allocate a buffer for us
  getline(&line, &bufsize, stdin);
  return line;
}*/
bool strcmp(char *s1, char *s2)
{

	size_t l1=strlen(s1);
	size_t l2=strlen(s2);

	if(l1!=l2)
	{
		return false;
	}
	else
	{

		while(s1[l1-1]==s2[l2-1])
		{
			// move in the string from right to left one character each
			l1--;
			l2--;


		}
		if(l1 == l2 && l1=-1) // if l1=l2=0 then both of them are equal and reached till 
			return true
	}
	return false;
	
}


int main()
{
		 // have getline allocate a buffer for us
  

	char * s1=NULL,*s2=NULL;

	size_t size1,size2; 
	getline(&s1, &size1, stdin);
	getline(&s2, &size2,stdin);


	//char *r= lsh_read_line
	return 0;
}

