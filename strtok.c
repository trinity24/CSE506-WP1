#include <string.h> /* strspn() strcspn() */
#include <stdio.h>
char *strtok(char * str, const char * delim)
{
    static char* p=0;
    if(str)
        p=str;
    else if(!p)
        return 0;
    str=p+strspn(p,delim);
    p=str+strcspn(str,delim);
    if(p==str)
        return p=0;
    p = *p ? *p=0,p+1 : 0;
    return str;
}
int main()
{
    printf("sh\n");
    char *s=strtok("sharmila is a good girl" , ";,/ ");
    printf("%s\n", s);
    return 0;
}