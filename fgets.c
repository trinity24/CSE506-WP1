#include <stdio.h>
#include <unistd.h>

/**  fgetc(fp) -- get char from stream */

int fgetc(FILE *fp)
{
	char c;
	
	if (fp->ungetcflag) {
		fp->ungetcflag = 0;
		return (fp->ungetchar);
	} 
	if (read (fp->fd, &c, 1) == 0)
			return (EOF);
	return (c);
}	
//char *fgets(dst,max,fp) -- get string from stream */

char *fgets(char *dst, int max, FILE *fp)
{	
	printf("into gets \n");
	int c;
	char *p;
	printf("%d and %zd are \n",max, fp );
	/* get max bytes or upto a newline */

	for (p = dst, max--; max > 0; max--) {
		if ((c = fgetc (fp)) == EOF)
			break;
		*p++ = c;
		if (c == '\n')
			break;
	}
	*p = 0;
	if (p == dst || c == EOF)
		return NULL;
	return (p);
}

int main()
{
	printf("in main\n");
	char* s=NULL;
	//s=(char *)(malloc(sizeof(char *)*10)
	printf("going into gets \n");

	fgets(s,10,stdin);


	printf("%s\n",s );
	return 0;	
}