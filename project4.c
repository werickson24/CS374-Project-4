#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

int main(int argc, char *argv[]){
  int p[2];

  //create pipe
  if (pipe(p) != 0){
    perror("pipe");
    exit(1);
  };

  //fork child
  pid_t pid = fork();
  switch(pid){
    case -1:
      perror("fork");
      exit(1);
      break;
    case 0:

      dup2(p[0], 0);
      close(p[1]);
      execlp("wc", "wc", "-l", NULL);

      exit(1);
      break;
    default:

      dup2(p[1], 1);
      close(p[0]);
      execlp("ls", "ls", "-1a", argv[1], NULL);//argv will either be some path, or it'll just be null
      wait(NULL);
      break;
  }
}
