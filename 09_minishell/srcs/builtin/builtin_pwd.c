#include <limits.h>
#include <stddef.h>

void	builtin_pwd(int argc, char *argv[])
{
	char	*buf[PATH_MAX];

	if (getcwd(buf, sizeof(buf)))
		ft_putendl_fd(buf, 1);
	else
		ft_perror(NULL);
}
