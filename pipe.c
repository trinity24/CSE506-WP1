#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <string.h>
#include <stdlib.h>
/*
for cmd in cmds
    if there is a next cmd
        pipe(new_fds)
    fork
    if child
        if there is a previous cmd
            dup2(old_fds[0], 0)
            close(old_fds[0])
            close(old_fds[1])
        if there is a next cmd
            close(new_fds[0])
            dup2(new_fds[1], 1)
            close(new_fds[1])
        exec cmd || die
    else
        if there is a previous cmd
            close(old_fds[0])
            close(old_fds[1])
        if there is a next cmd
            old_fds = new_fds
if there are multiple cmds
    close(old_fds[0])
    close(old_fds[1])
*/
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
    s=(char*)(malloc(sizeof(char)*size));
    while((c=Mygetc())!='\n' && i<size)     
        s[i++]=c;
    s[i]='\0';
    return s;
}
int main()
{
    int i,status;
    char *readline= NULL;
    pid_t pid1,pid2,pid3;
    char *command,*argv[3];

    int fd[4]; // pipe 1 and pip2 are two pipes with pipe1[0] as filedescriptors/ 
    char *eachcommand[3];
  

    //Read string
    readline=Mygets(readline,100);
    
    for(i=0;i<3;i++)
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


    pipe(fd);
    pipe(fd+2);
    pid1=fork();

    if(pid1==-1)
    {
        printf("fork failed\n");
    }
    else if(pid1==0)
    {   
        pid2=fork();
        printf("In first child\n");
        if(pid2==0)
        {   
            printf("In second child, execution of first is done...\n");
            pid3=fork();
            if(pid3<0)
            {
              printf("error in pid3\n");
            }
            else if(pid3==0)
            {

              printf("In third child, execution of secpmd  is done...\n");
              close(fd[3]);
              dup2(fd[2],0); 
              command=strtok(eachcommand[2]," ");
              argv[0]=command;
              if(strtok(NULL," "))
                argv[1]=strtok(NULL," ");
              else
                argv[1]="-l";
              argv[2]=0; 
              close(fd[1]);
              close(fd[0]);
              close(fd[2]);
              close(fd[3]);
              if(execvp(command,argv)==-1)
                {
                  printf("error in wc\n");
                }
                exit(EXIT_FAILURE);

            }
            else
            {

              printf("second process is here, ready to execute\n");
              dup2(fd[0],0);
              dup2(fd[3],1);
              command=strtok(eachcommand[1]," ");
              argv[0]=command;
              argv[1]=strtok(NULL," ");
              argv[2]=0;   

              close(fd[1]);
              close(fd[0]);
              close(fd[3]);
              close(fd[2]);

              if(execvp(command,argv)==-1)
                printf("error in child 1\n");
              exit(EXIT_FAILURE);

            }
         }
         else
         {
            printf("gonna excute the first process now\n");
            dup2(fd[1],1);
            command=strtok(eachcommand[0]," ");
            argv[0]=command;
            argv[1]=strtok(NULL," ");
            argv[2]=0;  
            //printf("%s\n",command );
            close(fd[1]);
            close(fd[0]);
            execvp(command,argv);
            exit(EXIT_FAILURE);

         }
      }
    
        
    else
    {
        printf("parent is waiting\n");
        waitpid(pid3,&status,WUNTRACED);
        waitpid(pid2,&status,WUNTRACED);
        waitpid(pid1,&status,WUNTRACED);
        printf("parent done waiting\n");
       
    }
    return 0;

}