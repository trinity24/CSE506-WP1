
int  Myputc(char *c)
{
	write(1,c,1);
    return 1;
}
int Myputs(char *s)
{
	int count;
	while(*s!='\0')
	{
		Myputc(s);
		s++;
		count++;

	}
	return count;
}

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