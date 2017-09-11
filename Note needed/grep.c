#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>

int main()
{
 


  char *readline= NULL;
  int fd;
  size_t readlineSize =0;
  char buff[1000];
  char *eachCommand=NULL;char *path=NULL;

 
  getline(&readline, &readlineSize, stdin);
  eachCommand=strtok(readline," \n");
  path=strtok(NULL," \n");
  printf("%s\n",path );
  if(!strcmp(eachCommand,"cat"))
  {
    fd=open(path,'r');
    printf("%d\n",fd );
    read(fd,buff,1000);

  }
  printf("%s\n",buff);




return 0;
}