#include "env.h"

void	builtin_unset(int argc, char *argv[], t_env *env)
{
	t_enode	*prev;
	t_enode	*curr;
	int		i;

	i = 0;
	while (++i < argc)
	{
		prev = env->head->next;
		while (prev && prev->next)
		{
			curr = prev->next;
			if (ft_strcmp(argv[i], curr->key) == 0)
			{
				prev->next = curr->next;
				delete_enode(curr);
				break ;
			}
			prev = curr;
		}
	}
}
