#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    int pipe_fds1[2], pipe_fds2[2];
    pid_t pid;
    if (pipe(pipe_fds1) == -1 || pipe(pipe_fds2) == -1) {
        perror("pipe");
        exit(EXIT_FAILURE);
    }
    pid = fork();
    if (pid == -1) {
        perror("fork");
        exit(EXIT_FAILURE);
    }
    if (pid == 0) {
        close(pipe_fds1[1]);
        close(pipe_fds2[0]);
        char buffer[1024];
        int bytes_read = read(pipe_fds1[0], buffer, sizeof(buffer));
        if (bytes_read > 0) {
            printf("Child received: %s", buffer);
            char message[] = "Hello back from the child!\n";
            write(pipe_fds2[1], message, sizeof(message));
        }
        close(pipe_fds1[0]);
        close(pipe_fds2[1]);
        exit(EXIT_SUCCESS);
    }
    else {
        close(pipe_fds1[0]);
        close(pipe_fds2[1]);
        char message[] = "Hello from the parent!\n";
        write(pipe_fds1[1], message, sizeof(message));
        char buffer[1024];
        int bytes_read = read(pipe_fds2[0], buffer, sizeof(buffer));
        if (bytes_read > 0) {
            printf("Parent received: %s", buffer);
        }
        close(pipe_fds1[1]);
        close(pipe_fds2[0]);
    }

    return EXIT_SUCCESS;
}
