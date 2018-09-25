#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <ctype.h>
#include <time.h>
#include <errno.h>

#define SIZE 1024


int main (int argc, char* argv[]) {

    gid_t list[SIZE];
    uid_t uid = getuid();
    uid_t gid = getgid();
    printf("UID=%ld   GID=%ld\n",
            (long) uid, (long) gid);
    printf("Group: %ld\n",
             getgroups(SIZE, list ));
    return 0;
}

