#include <stdio.h>
#include <string.h>
int main()
{


	char *readline= NULL;
   size_t readlineSize =0;
   
   char *tokensString=NULL,*tokensString_path=NULL;

   getline(&readline, &readlineSize, stdin);
   char *ptr = strtok(readline," \n");

   while (ptr) {
   		printf("%s\n", ptr);
   		ptr = strtok(NULL," \n");
   }
   
   //printf("%s\n",s);
   printf("test \n");
	//printf("%s\n", s);

	return 0;
}