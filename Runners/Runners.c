#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <ctype.h>
#include <time.h>
#include <errno.h>
#include <pwd.h>

int main (int argc, char* argv[]) {
    int NumberOfRunners = argc;
    int i = 0;
    for (i = 0; i <= NumberOfRunners, i++)
    {
        printf("Runner mumber %i come\n", &i);

    }


    return 0;
}

void dread (int NumberOfRunners) {
    printf("YA Priwol\n");
    printf("Priwo %i begunov", &NumberOfRunners);
    printf("%d\n", time());
    printf("Ya Uwol");
}

void runner () {
    printf("Start run\n");
    printf("Finish run\n");

}
