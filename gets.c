#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
char Mygetc()
{
    char *c=NULL;
    c=(char *)malloc(sizeof(char));
    read(0,c,1);
    return *c;
}
char *Mygets(char *s,int size)
{
    char c;
    int i=0;
    char *s1;
    s1=(char*)(malloc(sizeof(char)*100));
    while((c=Mygetc())!='\n' && i<size)
    {
            
        s1[i++]=c;
    }
    s1[i]='\0';
    s=s1;
    return s;

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
    int fd=open(filename,'r');
    char eachline[100];
    char c;int i=0;
    char buffer[20];
    int bytes_read;
    int k = 0;
    
    do {
        char t;
        char n1=EOF;
        char n2='\n';
        bytes_read = read(fd, &t, 1); 
        buffer[k++] = t;    
        //printf("%c",t );
        
        
        if(!(t ^ n1) ||!( t^n2)) {
            
            for( i=0;i<k;i++)
                printf("%c",buffer[i] );
            for(i=0; i<20; i++) 
                buffer[i]='\0';
                k = 0;
            }
            

            
        }while (bytes_read != 0); 
        for(int i=0;i<k;i++)
        {
            printf("%c",buffer[i] );
        }

    return ;
  
 } 
        

int main()
{
	char *s1=NULL,*s2=NULL;
	int size=100;
    execute_script("/Users/sharmila24/Documents/shar.txt");
	return 0;

}