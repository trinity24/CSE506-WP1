#include <stdio.h>
void print(char* message){

  unsigned long syscall_write = 1;
  unsigned long syscall_exit = 60;
  //char* message  = "Hello world\n";
  long file_desc=1;
  long  no_bytes=stringLength(message);
  long  exit_status = 42;
  asm ( "movq %0, %%rax\n"
        "movq %1, %%rdi\n"
        "movq %2, %%rsi\n"
        "movq %3, %%rdx\n"
        "syscall\n"
        "movq %4, %%rax\n"
        "xor %5,  %%rdi\n"
        "syscall"
    : /* output parameters, we aren't outputting anything, no none */
      /* (none) */
    : /* input parameters mapped to %0 and %1, repsectively */
      "m" (syscall_write), "m" (file_desc), "m" (message),"m" (no_bytes),"m" (syscall_exit), "m" (exit_status)
    : /* registers that we are "clobbering", unneeded since we are calling exit */
      "rax", "rdi","rsi","rdx");
}

void print(char* message){

  unsigned long syscall_write = 1;
  unsigned long syscall_exit = 60;
  //char* message  = "Hello world\n";
  long file_desc=1;
  long  no_bytes=stringLength(message);
  long  exit_status = 42;
  asm ( "movq %0, %%rax\n"
        "movq %1, %%rdi\n"
        "movq %2, %%rsi\n"
        "movq %3, %%rdx\n"
        "syscall\n"
        "movq %4, %%rax\n"
        "xor %5,  %%rdi\n"
        "syscall"
    : /* output parameters, we aren't outputting anything, no none */
      /* (none) */
    : /* input parameters mapped to %0 and %1, repsectively */
      "m" (syscall_write), "m" (file_desc), "m" (message),"m" (no_bytes),"m" (syscall_exit), "m" (exit_status)
    : /* registers that we are "clobbering", unneeded since we are calling exit */
      "rax", "rdi","rsi","rdx");
}



int main()
{

}