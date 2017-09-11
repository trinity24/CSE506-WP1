#include<sys/types.h>
#include<sys/stat.h>
#include<dirent.h>
#include<fcntl.h>
#include<stdio.h>

int main()
{
DIR *dp;
struct dirent *p;
dp=opendir("Desktop");
p=readdir(dp);
while(p!=NULL)
{
printf("%s\n",p->d_name);
p=readdir(dp);
}
return 0;
}