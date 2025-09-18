#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
	// Creates a process
	int rc = fork();
	// fork() failed
	if (rc < 0) {
		fprintf(stderr, "fork failed\n");
		exit(1);
	}
	// Child process
	else if (rc == 0) {
		printf("hello, I am child (pid:%d)! Executing '/bin/ls'...\n", (int) getpid());
		execl("/bin/ls", "ls", NULL);
		// If exec fails
		perror("execl() failed");
		exit(1);
	}
	// Parent process
	else {
		wait(NULL);
		printf("hello, I am parent of %d (pid:%d)! After child process...\n", rc, (int) getpid());
	}
	return 0;
}
