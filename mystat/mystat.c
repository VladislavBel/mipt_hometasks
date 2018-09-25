#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <ctype.h>
#include <time.h>
#include <errno.h>


int main (int argc, char* argv[])
{
    struct stat sb;
    stat(argv[1], &sb);

    if (argc != 2) {
        printf("invalid value");
        return 0;
    }

    if (stat(argv[1], &sb) == -1) {
        perror("stat");
        return 0;
    }

    printf("Owner:                    UID=%ld   GID=%ld\n",
           (long) sb.st_uid, (long) sb.st_gid);
    printf("Mode:                     %lo (octal)\n",
           (unsigned long) sb.st_mode);
    printf("block size: %ld bytes\n",
           (long) sb.st_blksize);
    printf("File size:                %lld bytes\n",
           (long long) sb.st_size);
    printf("Blocks allocated:         %lld\n",
           (long long) sb.st_blocks);

    printf("Last change:       %s", ctime(&sb.st_ctime));
    printf("Last access:         %s", ctime(&sb.st_atime));
    printf("Last modification:   %s", ctime(&sb.st_mtime));

    return 0;
}

