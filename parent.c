#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>

#define MAX_LENGTH 200

int main(){

	char file_name[MAX_LENGTH];
	printf("Enter file name for child process: ");
	scanf("%s", file_name);

	int file = open(file_name, O_RDONLY);

	if (file < 0){
		perror("Can't open file");
		return 2;
	}

	//creating pipe
	int fd[2];
	if (pipe(fd) < 0){
		perror("Can't create a pipe");
		return 3;
	}

	//creating child process
    int pid = fork();
	if (pid < 0){
		perror("Cant't create child process");
	}
	
	if (pid > 0){//parent
		close(fd[1]);
		int x;
		while(1){
		read(fd[0],&x,sizeof(int));
		printf("%d\n",x);
		fflush(stdout);
		}
		close(fd[0]);
	}
    else{//child
		close(fd[1]);
		if(dup2(file,0) < 0){
			perror("Can't redirect standard output for child process");
		}
		if(dup2(fd[1],1) < 0){
			perror("Can't redirect standard input for child process");
		}
		execl("child",NULL,NULL);
    }

}