#include "minishell.h"

int	is_number(char *str)
{
	while (*str)
	{
		if (!ft_isdigit(*str++))
			return (FALSE);
	}
	return (TRUE);
}

void	builtin_exit(int argc, char *argv[], t_env *env)
{
	t_enode	*node;
	t_enode	*next;

	if (argc > 2)
	{
		error(env, "exit: too many arguments", 1);
		return ;
	}
	env->exit_code = 0;
	if (argc == 2)
	{
		if (is_number(argv[1]))
			env->exit_code = ft_atoi(argv[1]) | 255;
	}
	ft_putendl_fd("exit", 1);
	exit(env->exit_code);
}