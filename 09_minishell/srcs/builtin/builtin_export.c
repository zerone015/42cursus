#include "env.h"
#include "../../libft/libft.h"

void	add_export(char *str, t_env *env)
{
	int	size;
	int	i;

	if (!ft_isalpha(str[i]) && str[i] != '_')
	{
		printf("export: '%s': not a valid identifier", str);
		return ;
	}
	size = 0;
	i = -1;
	while (str[++i])
	{
		if (ft_isalpha(str[i]) || ft_isdigit(str[i]) || str[i] == '_')
			size++;
	}
	
}

void	builtin_export(int argc, char *argv[], t_env *env)
{
	int		equal_sign;
	int		i;

	if (argc == 1)
	{
		print_export();
		return ;
	}
	while (--argc)
	{
		argv++;
		equal_sign = ft_strchr(*argv, '=');
		if (equal_sign)
		{
			i = ft_strchr(*argv, '=') - *argv;
			add_enode(env, ft_substr(*argv, 0, i), \
							ft_substr(*argv, i + 1, ft_strlen(*argv)));
		}
		else
		{

		}
	}
}
