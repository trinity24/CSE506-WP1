
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
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
    char *tokens=NULL;
    char *string1,*string2;
    string1=Mygets(string1,100);
    string2=Mygets(string2,100);
  
    


    return 0;
}