#include <stdio.h>


inline long MyOpendef(long syscallNum,const char *file,int flag, mode_t mode)
{
	return __asm__ __volatile__ ("int $0x80":"=a"(ret):"a"(syscallNum), "b"(file), "c"(flag),"d"(mode):"memory");

}
inline int Mygetdents(long syscallNum,unsigned int fd, void * mydirent, unsigned int count)
{
	return __asm__ __volatile__ ("int $0x80":"=a"(ret):"a"(syscallNum), "b"(fd), "c"(mydirent),"d"(count):"memory");
}


inline long MyWritedef(long syscallNum,unsigned int fd, char * buf, size_t count)
{
	return __asm__ __volatile__ ("int $0x80":"=a"(ret): "a"(syscallNum),"b"(fd), "c"(buf),"d"(count):"memory");

}

inline long MyReaddef(long syscallNum,unsigned int fd, const char *buf,size_t count)
{
	return __asm__ __volatile__ ("int $0x80":"=a"(ret):"a"(syscallNum), "b"(fd), "c"(buf),"d"(count):"memory");
}

inline pid_t MyWaitpiddef(long syscallNum,pid_t pid,int *status, int options)
{
	return __asm__ __volatile__ ("int $0x80":"=a"(ret): "a"(syscallNum),"b"(pid), "c"(status), "d"(options):"memory");
}

inline pid_t MyFork(long syscallNum)
{
	return __asm__ __volatile__ ("int $0x80":"=a"(ret): "a"(syscallNum):"memory");
}

inline int MyPipe(long syscallNum,int *fildes)
{
	return __asm__ __volatile__ ("int $0x80":"=a"(ret):"a"(syscallNum), "b"(filedes):"memory");
}

