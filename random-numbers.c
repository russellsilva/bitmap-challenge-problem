#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    srand(time(NULL));

    unsigned int num_iterations = 10;
    if (argc > 1) {
        sscanf(argv[1], "%u", &num_iterations);
    }


    for (unsigned int i = 0; i < num_iterations; i++) {
        unsigned int r = rand();
        printf("%u\n", r);
    }
}
