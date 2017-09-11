#include <stdio.h>

inline long MyOpendef(const char *file,int flag, mode_t mode)
{
	__asm__ __volatile__ ("int $0x80":"=a"(ret): "a"(args), "b"(uhauj):"memory");


	
}
{

}