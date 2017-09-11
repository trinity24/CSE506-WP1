#include <stdio.h>
#include <Mysyscalls.h>

char file_global[300];
char buff_global[300];
int *filedes;

int Mygetdents(unsigned int fd, void * mydirent, unsigned int count)
{
	return Mygetdents(78,fd,mydirent,count)
}
long MyOpen(const char *file,int flag, mode_t mode)
{
	int i=0;
	while(file[i]!='\0')
	{
		file_global[i]=file[i];
	}
	


	return MyOpendef(2,file_global,flag,777);


}

long MyWrite(unsigned int fd, char * buf, size_t count)
{
	int i=0;
	while(file[i]!='\0')
	{
		buff_global[i]=file[i];
	}
	return MyWritedef(1,fd,buff_global,count);

}
long MyRead(unsigned int fd, const char *buf,size_t count)
{
	int i=0;
	while(file[i]!='\0')
	{
		buff_global[i]=file[i];
	}


	return MyReaddef(0,fd,buff_global,count);
}

pid_t MyWaitpid(pid_t pid,int *stat_add, int options)
{
	int i=0;
	while(file[i]!='\0')
	{
		buff_global[i]=file[i];
	}

	return MyWaitpiddef(247,pid, buff_global,options);
}
pid_t MyFork()
{
	return MyForkdef(57);
}
int MyPipe(int *fildes)
{
	filedes= filedes;
	return MyPipedef(22,filedes);
}


