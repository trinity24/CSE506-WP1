#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>

/**
 * Executes the command "cat scores | grep Villanova | cut -b 1-10".
 * This quick-and-dirty version does no error checking.
 *
 * @author Jim Glenn
 * @version 0.1 10/4/2004
 */

int main(int argc, char **argv)
{
  int status;
  int i;

  // arguments for commands; your parser would be responsible for
  // setting up arrays like these
  char *readline= NULL;

  size_t readlineSize =0;
  char *command,*args;
  char *eachCommand;

  //Read string
  getline(&readline, &readlineSize, stdin);

  printf("readline = %s\n",readline );

  char *cat_args[] = {"cat", "scores", NULL};
  char *grep_args[] = {"grep", "Villanova", NULL};
  char *cut_args[] = {"cut", "-b", "1-10", NULL};

  // make 2 pipes (cat to grep and grep to cut); each has 2 fds
  for(int i=0;i<)
  int pipes[4];
  pipe(pipes); // sets up 1st pipe
  pipe(pipes + 2); // sets up 2nd pipe

  // we now have 4 fds:
  // pipes[0] = read end of cat->grep pipe (read by grep)
  // pipes[1] = write end of cat->grep pipe (written by cat)
  // pipes[2] = read end of grep->cut pipe (read by cut)
  // pipes[3] = write end of grep->cut pipe (written by grep)

  // Note that the code in each if is basically identical, so you
  // could set up a loop to handle it.  The differences are in the
  // indicies into pipes used for the dup2 system call
  // and that the 1st and last only deal with the end of one pipe.

  // fork the first child (to execute cat)
  
  if (fork() == 0)
    {
      // replace cat's stdout with write part of 1st pipe
      printf("here\n");
            eachCommand=strtok(readline, "|");
      //printf("here is print statement\n");  
      printf("%s is eachCommand\n", eachCommand);
      command=strtok(eachCommand," ");
      args =strtok(NULL,"");
      printf("The command is %s and the args are %s ---FIrst Child\n", command, args);
      dup2(pipes[1], 1);

      printf("here after dup2\n");

      // close all pipes (very important!); end we're using was safely copied

      close(pies[0]);x
      close(pipes[1]);
      close(pipes[2]);
      close(pipes[3]);
      printf("%s\n", *cat_args);

      execvp(eachCommand,&args);
      //execvp(*cat_args, cat_args);
    }
  else
    {
      // fork second child (to execute grep)

      if (fork() == 0)
  {
    // replace grep's stdin with read end of 1st pipe
         printf("here\n");
            eachCommand=strtok(readline, "|");
      //printf("here is print statement\n");  
      printf("%s is eachCommand\n", eachCommand);
      command=strtok(eachCommand," ");
      args =strtok(NULL,"");
      printf("The command is %s and the args are %s ---FIrst Child\n", command, args);
    dup2(pipes[0], 0);

    // replace grep's stdout with write end of 2nd pipe

    dup2(pipes[3], 1);

    // close all ends of pipes

    close(pipes[0]);
    close(pipes[1]);
    close(pipes[2]);
    close(pipes[3]);

    execvp(eachCommand,&args);
  }

    }
      
  // only the parent gets here and waits for 3 children to finish
  
  close(pipes[0]);
  close(pipes[1]);
  close(pipes[2]);
  close(pipes[3]);

  for (i = 0; i < 3; i++)
    wait(&status);
}
