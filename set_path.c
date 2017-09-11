#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
int main()
{
   //char command[50];
  char *readline=NULL, *pathVariable="export",*path="PATH",*var;
  char *tokens=NULL,*tokens1=NULL;
  size_t readlineSize=0;
  getline(&readline, &readlineSize, stdin);
  tokens= strtok(readline," ");
  //printf("%s\n",tokens );
  //printf("%s\n",pathVariable );
    /*if(tokens==pathVariable)
    {
      printf("yes yes\n");
    }*/
    if(!strcmp(tokens,pathVariable))
    {
      //printf("yes pathVariable matched\n");

      tokens=strtok(NULL," ");
       // printf("%s\n",tokens );

      tokens1=strtok(tokens,"=");
       // printf("%s\n",tokens1 );

      if(!strcmp(tokens1,path))
      {
          tokens1=strtok(NULL,"");
           // printf("%s\n",tokens1 );
          

          setenv(tokens1,strcat(strcat(getenv("PATH"),":"),tokens1),1);
          printf("After changing the environment variable is %s\n", getenv("PATH"));


      }
    }
    else
    {
        tokens = strtok(tokens,"=");
        //printf("%s\n", tokens);
        tokens1 = strtok(NULL,"\"");
        
        //printf("%s\n", tokens1);
        setenv(tokens, tokens1,1);
        printf("After changing the environment variable is %s\n",getenv(tokens) );
     }
    

return 0;
}

