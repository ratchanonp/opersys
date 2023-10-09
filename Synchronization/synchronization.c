/**
 * Synchronization
 * Ratchanon Panmas
 * 6434480323
*/

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define MAX_THREADS 4
#define MAX_ELEM 1000

int arr[MAX_ELEM];
int next = 0;
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

void *thread_update(void *arg) {
    int tid = *(int *)arg;
    free(arg);

    // Keep updating array until it's full
    while (1) {
        // Only one thread can update the array at a time
        pthread_mutex_lock(&mutex);
        if (next >= MAX_ELEM) {
            pthread_mutex_unlock(&mutex);
            break;
        }
        arr[next++] = tid;
        pthread_mutex_unlock(&mutex);

    }

    return NULL;
}

int main() {
    // Create threads
    pthread_t threads[MAX_THREADS];

    for (int tid = 0; tid < MAX_THREADS; tid++) {
        int *arg = malloc(sizeof(int));
        if (!arg) {
            fprintf(stderr, "Error allocating memory\n");
            exit(1);
        }
        *arg = tid;
        if (pthread_create(&threads[tid], NULL, thread_update, arg) != 0) {
            fprintf(stderr, "Error creating thread\n");
            exit(1);
        }
    }

    // Join threads
    for (int tid = 0; tid < MAX_THREADS; tid++)
        if (pthread_join(threads[tid], NULL) != 0) {
            fprintf(stderr, "Error joining thread\n");
            exit(1);
        }

    // Print array
    for (int i = 0; i < MAX_ELEM; i++)
        printf("%d ", arr[i]);

    return 0;
}