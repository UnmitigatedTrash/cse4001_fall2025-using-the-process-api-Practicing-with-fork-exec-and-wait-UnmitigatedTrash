#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

int main(int argc, char *argv[]) {
	printf("hello world (pid:%d)\n", (int) getpid());
	// Opens a file
	int file = open("example.txt", O_WRONLY, 0644);
	// Create text assignment beforehand
	const char *text = "";
	// Creates a process
	int rc = fork();
	// fork() failed
	if (rc < 0) {
		fprintf(stderr, "fork failed!\n");
		exit(1);
	}
	// Child process
	else if (rc == 0) {
		printf("hello, I am child (pid:%d)! Starting process...\n", (int) getpid());
		// Access file descriptor
		printf("File descriptor: %d\n", file);
		// Text to write
		text = "Written from child process!\n";
		// Writes text to example.txt
		ssize_t written = write(file, text, 28);
	}
	// Parent process
	else {
		printf("hello, I am parent of %d (pid:%d)! Starting process...\n", rc, (int) getpid());
		// Access file descriptor
		printf("File descriptor: %d\n", file);
		// Text to write
		text = "Written from parent process!\n";
		// Writes text to example.txt
		ssize_t written = write(file, text, 29);
	}
	close(file);
	return 0;
}
