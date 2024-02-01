#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <ctype.h>
#include <sys/types.h>

int main(int argc, char *argv[]){

  if(argc < 2){
    printf("Invalid number of arguments\n");
    exit(1);
  }

  int fd = open(argv[1], O_CREAT|O_WRONLY, 0644);

  pid_t pid = fork();

  switch(pid){
    case -1:
      perror("fork");
      exit(1);
      break;
    case 0:
      dup2(fd, 1);
      execvp(argv[2], &argv[2]);

      exit(1);
      break;
    default:
      //execlp("ls", "ls", "-1a", argv[1], NULL);//argv will either be some path, or it'll just be null
      wait(NULL);
      close(fd);
      break;
  }

}
