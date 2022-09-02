#include "minishell.h"

void	builtin_env(int argc, char *argv[], t_env *env)
{
	t_enode	*node;

	(void)env;
	node = env->head->next;
	while (node)
	{
		if (node->val)
		{
			ft_putstr_fd(node->key, 1);
			ft_putchar_fd('=', 1);
			ft_putstr_fd(node->val, 1);
		}
		node = node->next;
	}
}