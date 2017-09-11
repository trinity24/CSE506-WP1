#include <stdio.h>
#include <string.h>
char * strpbrk ( const char *, const char * )
{
  char str[] = "This is a sample string";
  char key[] = "aeiou";
  char * pch;
  printf ("Vowels in '%s': ",str);
  pch = strpbrk (str, key);
  while (pch != NULL)
  {
    printf ("%c " , *pch);
    pch = strpbrk (pch+1,key);
  }
  printf ("\n");
  return 0;
}
int main ()
{
  int i;
  char strtext[] = "sharmilasharmilsharmila";
  char cset[] = "sharmila";
  i = strspn (strtext,cset);
  printf ("The initial number has %d digits.\n",i);
  return 0;
}