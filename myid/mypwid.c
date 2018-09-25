
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <ctype.h>
#include <time.h>
#include <errno.h>
#include <pwd.h>

#define SIZE 1024


int main (int argc, char* argv[]) {
    printf("uid = %d gid = %d name = %d", getpwnam(argv[1]) -> pw_uid getpwnam(argv[1]) -> pw_gid  getpwnam(argv[1]) -> pw_name )
    return 0;
}

