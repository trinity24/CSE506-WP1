#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <fcntl.h>
char * concat(char *s1,char *s2)
{
  char *des =(char *)malloc(sizeof(char*)*(strlen(s1)+strlen(s2))+1);
  int l1=strlen(s1);
  int l2=strlen(s2);

  for(int i=0;i<strlen(s2);i++)
  {

    *(des+i)=*(s1+i);
  }
 // printf("going on for secind string\n");
  for(int i=0;i<strlen(s2);i++)
  {
    //
    *(des+l1+i)=*(s2+i);
  }
  *(des+1+l1+l2)='\0';
  return des;
} 
int main()
{
  
  
 
  pid=fork();
   		if(pid==0)
   		{
   			printf("in child process\n");
   			printf("%s and %s are the tokesn generated\n", tokensString_command,tokensString_path);
        args[0]=tokensString_command;
        args[1]="-H";
        args[2]=NULL;

        char str2[1024];
        getcwd(str2, sizeof(str2));
        printf("cwd: %s\n", str2);
        chdir(tokensString_path);
        char str3[1024];
        getcwd(str3, sizeof(str3));
        printf("cwd: %s\n", str3);

        if(strcmp(tokensString_command,"cd"))
        {
          printf("not cd\n");
   			  return_value =execvp(tokensString_command,args);
        }

   		}
   		else 
      {
        wait(&status);

   		}
   return 0 ;
}