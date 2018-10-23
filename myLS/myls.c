#include <stdio.h>
#include <stdlib.h>
#include <getopt.h>
#include <dirent.h>
#include <stdbool.h>


int main (int argc, char* argv[]) {
    /*DIR  *dptr;
    struct dirent *ds;
    dptr = opendir(argv[1]);
    int getopt_long (int argc, char* argv[], const char *optstring, const struct option *longopts, int *longindex);

    while((ds = readdir(dptr)) != NULL)
        printf("%s\n", ds -> d_name);
    closedir(dptr);*/

    bool key_a = 0;
    bool key_l = 0;
    bool key_n = 0;
    bool key_R = 0;
    bool key_i = 0;
    bool key_d = 0;
    char* str;
    int ScanParam = 0;
    ScanParam = scanf("%s", str);
    if (ScanParam != 1)
        return 0;
    int opt = 0;
    while ((opt != getopt(argc, argv, "alnRid")) != 1)
    {
        switch ()
        {
            case "l" :
                key_l = 1;
                break;

            case "a" :
                key_a = 1;
                break;

            case "n" :
                key_n = 1;
                break;

            case "R" :
                key_R = 1;
                break;

            case "i" :
                key_i = 1;
                break;

            case "d" :
                key_d = 1;
                break;
        }
    }

    return 0;
}