#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <string.h>
char Mygetc()
{
  char *c=NULL;
  c=(char *)malloc(sizeof(char));
  read(0,c,1);
  return *c;
}
char *   Mygets(char *s,int size)
{
  char c;
  int i=0;
  s=(char*)(malloc(sizeof(char)*size));
  while((c=Mygetc())!='\n' && i<size)
    s[i++]=c;
  s[i]='\0';
  return s;
}
int count_pipe(char *s)
{
	int i=0;
	while(*s!='\0')
	{
		if(*s=='|' )
			i++;
		s++;
	}
	return i;
}

int main()
{
	int i,status;
	char *readline= NULL; 
 	int count, iter;
 	readline =Mygets(readline,100);
 	count =count_pipe(readline);
 	int pipe_fd[2*count],j;
 	pid_t pid[count+1],pid1;
  char *eachcommand[count+1],*command[count+1],*argv[count+1][3];
  //parsing the pipe command into individual commands
  for(i=0;i<count+1;i++)
  {
    if(i==0)
    {
      eachcommand[i]=strtok(readline,"|");
      printf("%s\n",eachcommand[i] );
    }
    else
    {
      eachcommand[i]=strtok(NULL,"|\n");
      printf("%s\n",eachcommand[i] );

    }
  }

  //parsing each command from the given pipe command
  for(i=0;i<count+1;i++)
  {
    command[i]=strtok(eachcommand[i]," ");
    argv[i][0]=command[i];
    argv[i][1]=strtok(NULL," ");
    argv[i][2]=NULL;
  }

 	if(count%2==0)
 	 	iter=count/2;
  else
 		iter=(count+1)/2;
  //creating the pipes
	for(i=0;i<(iter);i++)
  {
 		pipe(pipe_fd+ 2*i);
 	}
  char buff[100];
  //forking the processes 
 	for(i=0;i<count+1;i++)
 	{
 		pid[i]=fork();
  	if(pid[i]==0)
 		{ 
      printf(" child process. %d\n",i+1 );
    	if(i<count) 
        dup2(pipe_fd[2*i+1],1);
          

      if(i!=0)
        dup2(pipe_fd[2*(i-1)],0);
      for(j=0;j<2*count;j++)
        close(pipe_fd[j]);
      if(i==1)
        read(0,&buff,10);
      perror("error in here\n");
    	if(execvp(command[i],argv[i])==-1) perror("error in execvp\n");
      //printf("execution of a process is done is %d\n",i);
 		}
  }
  for(i=0;i<count+1;i++)
  {
    printf("waiting for the processes\n");
    if(i==1)
      sleep(2); 
    waitpid(pid[i],&status,WUNTRACED);   
    printf("waiting done %d\n",i); 
    if(i==1)
      printf("%s\n",buff );
  }
   for(i=0;i<2*count;i++)
    close(pipe_fd[i]);

return 0;
}