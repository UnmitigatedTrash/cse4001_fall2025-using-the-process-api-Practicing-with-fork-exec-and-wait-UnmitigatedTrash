#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
	// Creates a process
	int status;
	int rc = fork();
	// fork() failed
	if (rc < 0) {
		fprintf(stderr, "fork failed\n");
		exit(1);
	}
	// Child process
	else if (rc == 0) {
		printf("hello, I am child (pid:%d)! Starting process...\n", (int) getpid());
		// Close standard output
		printf("Closing STDOUT_FILENO...\n");
		close(STDOUT_FILENO);
		// Try to print after closing standard output
		printf("Attempt to print after closing STDOUT_FILENO");
	}
	// Parent process
	else {
		printf("hello, I am parent of %d (pid:%d)! Forking child process...\n", rc, (int) getpid());
	}
	return 0;
}
