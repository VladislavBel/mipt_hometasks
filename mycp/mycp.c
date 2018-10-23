#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

#define PERMS 0666

void error(char *, ...);


main(int argc, char* argv[])
{
    int f1, f2, n;
    char buf[BUFSIZ];

    if (argc != 3)
    error("Обращение: cp откуда куда");
    if ((f1 = open(argv[1], O_RDONLY, 0)) == -1)
        error("cp: не могу открыть файл %s", argv[1]);
    if ((f2 = creat(argv[2], PERMS)) == -1)
        error("cp: не могу создать файл %s, режим %03o",
              argv[2], PERMS);
    while ((n = read(f1, buf, BUFSIZ)) > 0)
        if (write(f2, buf, n) != n)
            error ("cp: ошибка при записи в файл %s", argv[2]);
    return 0;
}
