#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
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
		// Waits until the child process is finished to continue
		int wc = waitpid(-1, &status, 0);
		printf("Child waiting with waitpid to finish...\n");
		printf("hello, I am child (rc:%d wc:%d) (pid:%d)! Starting process...\n", rc, wc, (int) getpid());
	}
	// Parent process
	else {
		// Waits until the child process is finished to continue
		int wc = waitpid(rc , &status, 0);
		printf("Parent waiting with waitpid for Child to finish...\n");
		printf("hello, I am parent of %d (wc:%d) (pid:%d)! After child process...\n", rc, wc, (int) getpid());
	}
	return 0;
}
