#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
	// Initialize x before the fork
	int x = 100;
	// Create the child process
    	int rc = fork();
	// fork() failed
    	if (rc < 0) {
        	fprintf(stderr, "fork failed\n");
        	exit(1);
	}
	// Child process
	else if (rc == 0) {
        	// Child goes down this path (child process)
		printf("hello, I am child (pid:%d)! Starting process...\n", (int) getpid());
		// x is originally 100
		printf("x = %d\n", x);
		// Modify x in child process
		x = 60;
		// x is now 60 in child process
		printf("new x = %d\n", x);
	}
	// Paret process
	else {
        	// Parent goes down this path (original process)
        	printf("hello, I am parent of %d (pid:%d)! Starting process...\n", rc, (int) getpid());
		// x is originally 100
		printf("x = %d\n", x);
		x = 80;
		// x is now 80 in parent process
		printf("new x = %d\n", x);
	}
	return 0;
}
