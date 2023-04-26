#include <stdio.h>
#include <stdlib.h>

/*
 * Sum integers in a file.
 */

int
main(int argc, char **argv)
{
    FILE *f;
    int x;
    int sum;

    if(argc != 2) {
        fprintf(stderr, "Usage: %s filename\n", argv[0]);
        exit(1);
    }

    f = fopen(argv[1], "r");
    if(f == 0) {
        /* perror is a standard C library routine */
        /* that prints a message about the last failed library routine */
        /* prepended by its argument */
        perror(argv[1]);
        exit(2);
    }

    /* else everything is ok */
    sum = 0;
    while(fscanf(f, "%d", &x) == 1) {
        sum += x;
    }

    printf("%d\n", sum);

    /* not strictly necessary but it's polite */
    fclose(f);

    return 0;
}