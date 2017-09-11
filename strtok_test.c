#include <stdio.h>
#include <stdlib.h>


int stringLength(char *s)
{
    printf("In strlen fucntion now: \n");
    int size=0;

    while(*s !='\0')
        {
            printf("Now counting started into loop  %c \n",*s);
            s++;
            
            size++;
        }
    return (size-1);


}

char* parsetoken(char *stringValue,char *delimeterValues)
{

    int tokenIndex=0;
    int eachtokenIndex=0;
    int start=0,end;
    int i,j;
    char delimeterValue;
    char *tokensString =NULL;
    static char *prev;
    if(stringValue==NULL)
    {
        if(prev==NULL)
        return prev;
        else
        {

        }
    }
    
   // char *s= stringValue;
    //tokensString = string that contains pointers to the start of each token. 
    //
   // for(i=0;i<)

    
    if(stringValue)
        tokensString=stringValue;
    else 
        return NULL;

    while(*tokensString!="\0")
    {
        if(i=findElement(tokensString,delimeterValues))
        {
            tokensString=stringValue+i; //check this once,
            printf(" %zd \n",tokensString);
            tokensString++;
        }
    }
    for(i=0;i<stringLength(delimeterValues);i++)
    {
        stringValue=tokensString+findElement(tokensString,delimeterValue);
    }
    stringValue=tokensString+findElement(tokensString,delimeterValues);
   /* p=str+strcspn(str,delim);
    if(p==str)
        return p=0;
    p = *p ? *p=0,p+1 : 0; */
    

    while(s[i]!='\0')
    {
        if(findElement(delimeterValues, s[i])!=-1)
        {  
            end=i;
            *tokensString[tokenIndex]=(char*)malloc(sizeof(char)*(end-start));

            for(j=start;j<end;j++)
            {
                printf("%c", s[j]);

                tokensString[tokenIndex][eachtokenIndex++]=s[j];

            }
            printf("x\n");

        }
        tokenIndex++;
        eachtokenIndex=0;
        start=end;
    }
    prev=tokensString;
    return tokensString;

}


int MystringCompariosn(char *s1, char *s2)
{

    int lenString1=stringLength(s1);
    int lenString2=stringLength(s2);

    if(lenString1!=lenString2)
    {
        printf("Both strings are not of same length\n");
        return 0;
    }
    else
    {
        printf("they are of same length\n");

        while(s1[lenString1-1]==s2[lenString2-1] && lenString1!=-1)
        {
            // move in the string from right to left one character each
            lenString1--;
            lenString2--;
            //printf("%d is the length of first string\n %d is the length of second string\n",lenString1,lenString2 );
        }
        if(lenString1 == lenString2 && lenString1==-1) // if l1=l2=0 then both of them are equal and reached till 
            {
               printf("Yes, it is successful all are matched\n");
                return 1;
            }
    }
    return 0;
    
}
int main()
{
    char *s1=NULL;
    int size=100;
    s1=Mygets(s,size);



    printf("%s\n", s);
    return 0;

}