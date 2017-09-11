#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <string.h>

void execute_command(char *readline);


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

void pipe2(char *readline)
{	
	int status,i=0;
	pid_t pid1,pid2;
    char *command,*argv[3];

    int fd[2]; // pipe 1 and pip2 are two pipes with pipe1[0] as filedescriptors/ 
    char *eachcommand[2];
    for(i=0;i<2;i++)
    {
      if(i==0)
      {
        eachcommand[i]=strtok(readline,"|");
        //printf("%s\n",eachcommand[i] );
      }
      else
      {
        eachcommand[i]=strtok(NULL,"|\n");
        //printf("%s\n",eachcommand[i] ); 
      }
    }


    if(pipe(fd)==-1)
    {
   	printf("error in pipe\n"); 	
    }

	pid1=fork();
    if(pid1==-1)
    {
        printf("fork failed\n");
    }
    else if(pid1==0)
    {
        if(pipe(fd)==-1){
   			printf("error in pipe\n"); 	
    	}
        pid2=fork();
        if(pid2==0)
        {
            //waitpid(pid2,&status,WUNTRACED);

            dup2(fd[0],0);
            command=strtok(eachcommand[1]," ");
            argv[0]=command;
            char *c=strtok(NULL," ");
            if(c)
                argv[1]=c;
            else 
                argv[1]="-l";
            argv[2]=0;   
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
            command=strtok(eachcommand[0]," ");
            argv[0]=command;
            argv[1]=strtok(NULL," ");
            argv[2]=0;  
            close(fd[1]);
            close(fd[0]);
            execvp(command,argv);

         }
  
    }
        
    else
    {
        //printf("parent is waiting\n");
        waitpid(pid2,&status,WUNTRACED);
        //printf("parent done waiting\n");
       
    }
}
void pipe3(char *readline)
{
	int i=0,status;	
	pid_t pid1,pid2,pid3;
    char *command,*argv[3];

    int fd[4]; // pipe 1 and pip2 are two pipes with pipe1[0] as filedescriptors/ 
    char *eachcommand[3];
  
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


    if(pipe(fd)==-1){
   	printf("error in pipe\n"); 	
    }
    if(pipe(fd+2)==-1){
   	printf("error in pipe\n"); 	
    }
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
            //printf("In second child, execution of first is done...\n");
            pid3=fork();
            if(pid3<0)
            {
              printf("error in pid3\n");
            }
            else if(pid3==0)
            {

              //printf("In third child, execution of secpmd  is done...\n");
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

              //printf("second process is here, ready to execute\n");
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
            //printf("gonna excute the first process now\n");
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
        waitpid(-1,&status,WUNTRACED);
       	// waitpid(pid2,&status,WUNTRACED);
       	// waitpid(pid1,&status,WUNTRACED);
        printf("parent done waiting\n");
       
    }
}
int MyfindElement(char *s,char c)
{
    int i=0;
    while(s[i]!='\0')
    {
        if(s[i]==c)
            return i;
       	i++;

    }
    return -1;
}
int  Myputc(char *c)
{
	if(write(1,c,1)==-1){
		printf("error in write\n");
	}
    return 1;
}
int Myputs(char *s)
{
	int c=0;
	while(*s!='\0')
	{
		Myputc(s);
		s++;
		c++;

	}
	return c;
}
char Mygetc()
{
    
    char *c=NULL;
    c=(char *)malloc(sizeof(char));
    if(read(0,c,1)==-1){
    	printf("error in read\n");
    }
    return *c;
}
char *Mygets(char *s,int size)
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
int Mystrlen(const char *s)
{
	//printf("In strlen fucntion now: \n");
	int size=0;
	if(s==NULL)
		return 0;

	while(*s !='\0')
		{
			//printf("Now counting started into loop  %c \n",*s);
			s++;
			
			size++;
		}
	return (size);
}


char * Mystrtok(char *str,char *delim)
{
	static char *prev;int i=0;


	int index=0,min_index;char *token=NULL;
	//if str =NULL then you say the str is the prev string
    if (!str) {
    	str=prev;
    	if(str==NULL)
		return NULL;
    }
    if (!str) return NULL;
    if (str) {
    	min_index=Mystrlen(str);
    	while(*delim!='\0')
    	{	
    		index = MyfindElement(str, *delim);
    		if(index!=-1)
    		{
    			if(index<min_index)
    			{
    				min_index=index;
    					
    			}

    			

    		}
    		delim++;
    	}
    	if(Mystrlen(str)==min_index)
   			prev=NULL;
   		else
   			prev=str+min_index+1;
    	if(index)
    	{    		
    		//copy the token to a new token	
    		token=(char *)malloc(sizeof(char *)*(min_index));
    		for(i=0;i<min_index;i++)
    		{

    			token[i]=str[i];
    		}
    	}
    		//change the give the string value to the prev. 
    		
    }	
    return token;

}

char * Mystrcat(char *s1, char *s2)
{
	int l1=Mystrlen(s1);
	int l2=Mystrlen(s2);
	

	char *s=(char *)(malloc(sizeof(char *)*(l1+l2)));
	if(s1==NULL)
		return s2;
	if(s2==NULL)
		return s1;
	if(s1==NULL && s2==NULL)
		return NULL;
	int i=0;
	int k1=l1,k2=l2;
	while(k1)
	{
		s[i]=s1[i];
		k1-=1;
		i++;
	}
	i=0;
	while(k2)
	{
		s[l1+i]=s2[i];
		i++;
		k2-=1;
	}

	s[l1+l2]='\0';
	return s;
}

int Mystrcmp(char *s1, char *s2)
{
    if(s1==NULL)
    {
        if(s2==NULL)
            return 1;
        else
            return 0;
    }
    if(s2==NULL)
        return 0;
    int l1=Mystrlen(s1);
    int l2=Mystrlen(s2);

    if(l1!=l2)
    {
        return 1;
    }
    else
    {
        int i=0;
        while(i<l1)
        {
            // move in the string from right to left one character each
            if(s1[i]==s2[i])
                i++;
            else
                return 1;
        }
        if(i==l1) // if l1=l2=0 then both of them are equal and reached till 
            return 0;
    }
    return 1;
} 

void execute_script(char * filename)
{
    int fd=open(filename,'r',777);
    char eachline[100];
    int i=0;
    
    for(i=0; i<100; i++) 
        eachline[i]='\0';
    int size ;
    int k = 0;
    
    do {
        char t;
        char n1=EOF;
        char n2='\n';
        size = read(fd, &t, 1); 
        eachline[k++] = t;    
        if(!(t ^ n1) ||!( t^n2)) {
            
     		execute_command(eachline);
            for(i=0; i<100; i++) 
                eachline[i]='\0';
                k = 0;
            }
        }while (size != 0); 

       	execute_command(eachline);

    return ;
  
 } 
void set_variable(char *readline)
{
	char *pathVariable="export",*path="PATH";
  	char *arg=Mystrtok(readline," ");
  	char *tokens= NULL,*tokens1=NULL,*value=NULL;
    if(Mystrcmp(arg,pathVariable)==0)
    {
    	//printf("yes comparison successful\n");
      	tokens=Mystrtok(NULL," ");
      	//printf(" Path full is %s\n",tokens);
      	tokens1=Mystrtok(tokens,"=");
      	
     	if(!Mystrcmp(tokens1,path))
      	{
          value=Mystrtok(NULL,"\n");
          printf("%s is the path value.\n",value );
          setenv(tokens1,Mystrcat(Mystrcat(getenv("PATH"),":"),value),1);
          Myputs("After changing the environment variable is  ");
          Myputs(getenv("PATH"));
      	}
    }	
    else
    {

        arg = Mystrtok(readline,"=");
        if(Mystrcmp(arg,"PS1 ")==0 || Mystrcmp(arg,"PS1")==0){
        	
        	value = Mystrtok(NULL," \n");
        	if(setenv("PS1", value,1)==-1){
        		Myputs("error\n");
        	}
        	Myputs("After changing the environment variable is  ");
        	Myputs(getenv("PS1"));
        	Myputs("\n");
        }
        else
        	Myputs("No way you can change this variable at this point of time \n");
    }   
    return;
}

void background(char *command)
{

	
 	pid_t pid;
   	
   	char *tokensString_command=NULL,*tokensString_path=NULL,*args[3];
   	
   	tokensString_command=Mystrtok(command," ");
   	Mystrtok(NULL," ");
   	tokensString_path=Mystrtok(NULL," ");
      
    pid=fork();
    args[0]=tokensString_command;
    args[1]="-l";
    args[2]=NULL;

   	if(pid==0)
   	{
   		
		
		if(chdir(tokensString_path)==-1){
        	printf("error in chdir\n");
        }
        //printf(" %s and \n", tokensString_command);
        execvp(tokensString_command,args);
   	}

   	return;
}

void ls_shell(char *command)
{
	char *args[3];
	int status,pid;
	char *tokensString_command=Mystrtok(command," ");
	char *tokensString_path=Mystrtok(NULL," ");
	pid=fork();
	if(pid==0)
	{
    	args[0]=tokensString_command;
    	args[1]="-H";
    	args[2]=NULL;
    	if(tokensString_path)
    		if(chdir(tokensString_path)==-1){
    			printf("error in chdir\n");};
    	execvp(tokensString_command,args);
	}
	else 
  		waitpid(pid,&status,WUNTRACED);
  	return;
}
void cd_shell(char *command)
{
	char *tokensString_command;
	tokensString_command=Mystrtok(command," ");
	char *tokensString_path=Mystrtok(NULL," ");
	char str1[1024];

    if(getcwd(str1, sizeof(str1))==NULL){
    	printf("error in getcwd\n");
    }
    printf("cwd: %s\n", str1);

	if(chdir(tokensString_path)==-1){
		printf("error in chdir\n");
	}

	char str3[1024];
     if(getcwd(str3, sizeof(str3))==NULL){
    	printf("error in getcwd\n");
    }

    printf("cwd: %s\n", str3);
    return;
}
void pipe_shell(char *readline)
{
	if(count_pipe(readline)==1)
		pipe2(readline);
	else if(count_pipe(readline)==2)
		pipe3(readline);
	else
		printf("for more pipes this is not efficient and the code is under construction\n");
}
void execute_command(char *readline)
{
    char *command;
    command=Mystrtok(readline," ");
    if(MyfindElement(readline,'&')!=-1)
        background(readline);  
    else if(MyfindElement(readline,'|')!=-1)
    	pipe_shell(readline);
    else if(!Mystrcmp(command,"ls"))
        ls_shell(readline); 
    else if(!Mystrcmp(command,"cd"))
        cd_shell(readline);  
    else if(!Mystrcmp(command,"sh"))
    {
    	command=Mystrtok(NULL," ");
        execute_script(command);
    }
    else if(Mystrcmp(command,"export")==0 || Mystrcmp(command,"PS1")==0)
        set_variable(readline);

    else printf("Sorry the command you enetered is invalid. Please find one of the below : cd /path, ls /path, ls &, sh x.sh, set_variables(path and ps1)\n");
    return;
}
int main()
{

	char *readline =NULL;
  	
  	do
  	{
  		Myputs("sbush> ");
  		readline= Mygets(readline,100);
  		execute_command(readline);
  	}while(Mystrcmp(readline,"exit")!=0);
  	
  	return 0;
}