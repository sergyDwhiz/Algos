/*
 Works by assigning each value in the input list to a separate
 thread, which then "sleeps" for a time proportional to the value,
 and then outputs the value after waking up. The result is that the
 values are output in sorted order.
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

void* sleep_sort(void* arg) {
    int num = *(int*)arg;
    sleep(num);
    printf("%d ", num);
    return NULL;
}

int main(int argc, char *argv[]) {
    pthread_t threads[argc-1];

    for (int i = 1; i < argc; i++) {
        int* num = malloc(sizeof(int));
        *num = atoi(argv[i]);
        pthread_create(&threads[i-1], NULL, sleep_sort, num);
    }

    for (int i = 0; i < argc - 1; i++) {
        pthread_join(threads[i], NULL);
    }

    printf("\n");
    return 0;
}
