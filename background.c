#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

//zomvieee
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
   //char command[50];
	//This code works for both cd and command;

   int exitcode,status;
   pid_t pid;
   char *readline= NULL,*x=NULL;
   size_t readlineSize =0;
   int flag1=0;
   char *tokensString=NULL,*tokensString_path=NULL,*args[3];
   char *s=" &",*y="&",*s1=NULL; 

      getline(&readline, &readlineSize, stdin);
      tokensString=strtok(readline, " \n");
      
      //printf("%s\n",tokensString );
      
      x =strtok(NULL," \n");
      
      //printf("%s\n", x);

      if(strcmp(x,y)==0)
      {
        flag1=1;
        //if both the strings are same then its a sign for background process
        tokensString_path=strtok(NULL," \n");
        tokensString=concat(tokensString,s);
        printf("path =%s\n", tokensString_path);

      }
      else
      {

        tokensString_path=x;
        printf("when they didnt match path = %s\n", tokensString_path);
      }
     
      pid=fork();

      //printf("%s\n", line);
      args[0]=tokensString;
      args[1]="-al";
      args[2]=NULL;

      if(pid==0)
      {
        char str2[1024];
        getcwd(str2, sizeof(str2));
        printf("cwd: %s\n", str2);
        // printf("%d\n",execvp(tokensString_command,&tokensString_path));
        // /tokensString_path = "/Users";
        chdir(tokensString_path);
        char str3[1024];
        getcwd(str3, sizeof(str3));
        printf("cwd: %s\n", str3);

        
          execvp(tokensString,args);
      }
      else if(pid>0)
      {
        printf("in parent process\n");
        //parent has to wait till child returns
        //exitcode = waitpid(pid,&status,WUNTRACED);
        
        // printf("exitcode is %d\n", exitcode);
      }
   		 
   return 0 ;
}