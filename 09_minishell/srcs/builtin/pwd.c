#include <limits.h>
#include <stddef.h>

void	pwd(int argc, char *argv[])
{
	char	*buf[PATH_MAX];

	if (getcwd(buf, sizeof(buf)))
		printf("%s\n", buf);
	else
		ft_perror(NULL);
}
