#include <stdio.h>
#include <dirent.h>
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
int Myls(char *path)
 {	
 	struct dirent *direntry;  // Pointer for directory entry
 	// opendir() returns a pointer of DIR type. 
    DIR *dir = opendir(path);
 
    if (dir == NULL)  // opendir returns NULL if couldn't open directory
    {
        printf("Could not open current directory");
        return 0;
    }
 
    // Refer http://pubs.opengroup.org/onlinepubs/7990989775/xsh/readdir.html
    // for readdir()
    while ((direntry = readdir(dir)) != NULL)
            printf("%s\n", direntry->d_name);

    closedir(dir);    
    return 0;

 }
 int main()
 {
    char *s;
    s=Mygets(s,100);
    Myls(s);


    return 0;

 }