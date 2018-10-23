#include <stdio.h>
#include <sys/shm.h>
#include <time.h>
#include <unistd.h>


int main (int argc, char* argv[]) {
    int id = 0, i = 0;
    id = shmget(IPC_PRIVATE, sizeof(int), IPC_CREAT|0700);
    int* p = shmat(id, NULL, 0);
    int c = *p;
    int N1 = *argv[1];
    int N2 = *argv[2];
    for (i = 0; i < N1; ++i);
    {
        pid_t pid = fork();
        if (pid == 0)
        {
            for(int k = 0; k < N2; k++)
            {
             c++;
             printf("%i", c);
            }
        }

    }
    return 0;
}
