#include <sys/types.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

const int n_proc = 4;
int child_list[4] = {0,0,0,0};

int main() {


    pid_t pid, pid1;

    /* fork a child process */
    for (int i = 0; i < n_proc; i++) {

        pid = fork();
        if (pid < 0) { /* error occurred */
            fprintf(stderr, "Fork Failed");
            return 1;
        }
        else if (pid == 0) { /* child process */
            pid1 = getpid();
            // printf("child: pid = %d\n",pid); /* A */
            // printf("child: pid1 = %d\n",pid1); /* B */
            exit(0); /* terminate child process */
        }
        else { 
            /* parent process */
            pid1 = getpid();

            /* add child process id to child_list */
            child_list[i] = pid;

            // printf("parent: pid = %d\n",pid); /* C */
            // printf("parent: pid1 = %d\n",pid1); /* D */

        }
    }


    // printf("parent: pid = %d\n",pid); /* C */
    printf("parent: pid1 = %d\n",pid1); /* D */

    for (int i = 0; i < n_proc; i++) {
        printf("child_list[%d] = %d\n", i, child_list[i]);
    }

    return 0;
}