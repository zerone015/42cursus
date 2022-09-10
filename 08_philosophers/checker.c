#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include "get_next_line.h"

int main(int argc, char *argv[])
{
	char	*str;
	char	*temp;
	int		cnt = 0;
	int		fd;

	fd = open("./result.txt", O_WRONLY | O_CREAT | O_TRUNC, 0777);
	while (1)
	{
		str = get_next_line(0);
		if (!str)
		{
			printf("read finished: ");
			break;
		}
		if (strstr(str, "died"))
			cnt++;
		temp = str;
		write(fd, temp, strlen(temp));
	}
	if (cnt < 1)
		printf("KO: cnt = %d\n", cnt);
	else
	{
		if (strstr(temp, "died"))
			printf("OK: cnt = %d\n", cnt);
		else
			printf("KO: cnt = %d\n", cnt);
	}
	return (0);
}
