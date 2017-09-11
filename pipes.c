#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <string.h>
char Mygetc()
{
    char *c=NULL;
    c=(char *)malloc(sizeof(char));
    read(0,c,1);
    return *c;
}
char* Mygets(char *s,int size)
{
    char c;
    int i=0;
    //c=Mygetc();
    //char *s1;
    s=(char*)(malloc(sizeof(char)*size));
    while((c=Mygetc())!='\n' && i<size)
    {
            
        s[i++]=c;
    }
    s[i]='\0';
    //s=s1;
    return s;

}
int main()
{
    int i,status;
    char *readline= NULL;
    pid_t pid1,pid2;

    char *command,*args;

    int fd[2]; // pipe 1 and pip2 are two pipes with pipe1[0] as filedescriptors/ 
    char *eachCommand=NULL;char *argv[3];
  

    //Read string
    readline=Mygets(readline,100);

    printf("readline = %s\n",readline );
   
    pid1=fork();
    if(pid1==-1)
    {
        printf("fork failed\n");
    }
    else if(pid1==0)
    {
        pipe(fd);
        pid2=fork();
        if(pid2==0)
        {
            //waitpid(pid2,&status,WUNTRACED);

            dup2(fd[0],0);

            command="grep";
            argv[0]="grep";
            argv[1]="shar";
            argv[2]=0;   
            //close(fd[0]);
            printf("child process will be 1 started\n");
            close(fd[1]);
            close(fd[0]);

            if(execvp(command,argv)==-1)
            {
                printf("error in child 1\n");
            }

            
         }
         else
         {

            if (dup2(fd[1],1)==-1)
            {
                printf("dup2 failed\n");
            }
            command="cat";
            argv[0]="cat";
            argv[1]="/Users/sharmila24/Documents/sharmila.txt";
            argv[2]=0;  
            close(fd[1]);
            close(fd[0]);
            execvp(command,argv);

         }
  
    }
        
    else
    {
        printf("parent is waiting\n");
        waitpid(pid2,&status,WUNTRACED);
        printf("parent done waiting\n");
       
    }

}