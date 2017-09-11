#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>

/**
 * Executes the command "cat scores | grep Villanova".  In this quick-and-dirty
 * implementation the parent doesn't wait for the child to finish and
 * so the command prompt may reappear before the child terminates.
 *
 * @author Jim Glenn
 * @version 0.1 9/23/2004
 */

int main(int argc, char **argv)
{
  int pipefd[2];
  int pid,d;

  char *cat_args[] = {"cat", "/Users/sharmila24/Fall2017/OS/wp1p1/sharmi.txt", NULL};
  char *grep_args[] = {"grep", "sharmi", NULL};

  // make a pipe (fds go in pipefd[0] and pipefd[1])

  pipe(pipefd);

  pid = fork();

  if (pid == 0)
    {
      // child gets here and handles "grep Villanova"

      // replace standard input with input part of pipe

      d=dup2(pipefd[0], 0);

      printf("yo succes %d\n",d);
      // close unused hald of pipe

      close(pipefd[1]);

      // execute grep
      printf("%s\n",*(grep_args+1) );
      execvp("grep", (grep_args+1) );
      printf("successfully executed\n");
    }
  else if(pid > 0)
    {
      // parent gets here and handles "cat scores"

      // replace standard output with output part of pipe

      d=dup2(pipefd[1], 1);

      // close unused unput half of pipe
      printf("yo succes %d\n",d);
      close(pipefd[0]);

      // execute cat

      execvp("cat", cat_args+1);
      printf("yo succes\n");
    }
    else {
      printf("error in fork\n");
    }
}
