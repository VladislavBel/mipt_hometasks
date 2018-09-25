#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <ctype.h>
#include <string.h>

#define SIZE 64

int main(int argc, char* argv[])
{
	int fdt[2];
	size_t size_buf = 0;
	char buffer[SIZE];
	int strings = 0, words = 0,chars = 0;   

	pipe(fdt);
	pid_t pid = fork();
	if(pid == 0)
	{
		close(fdt[0]);
		close(1);
		dup(fdt[1]);
		close(fdt[1]);
		int er = execvp(argv[1], argv + 1);
		if(er == -1)
			return 0;

	}
	wait(NULL);
	close(fdt[1]);
	while(read(fdt[0], buffer, SIZE) != 0)
	{
		size_buf = strlen(buffer);
		chars += size_buf;
		char* ptr = buffer;
		int word_count = 1;
		while(ptr = strchr(ptr, ' '))
		{
			if(!isspace(ptr[1]))
				word_count++;
			ptr++;
		}
		if(size_buf > 1)
			words += word_count;
		ptr = buffer;
		while(ptr = strchr(ptr, '\n'))
		{
			strings++;
			ptr++;
		}

				
	}
	printf("%d, %d, %d", strings, words, chars);
	return 0;
}
