#include "env.h"

void	builtin_env(t_env *env)
{
	t_enode	*node;

	node = env->head->next;
	while (node)
	{
		if (node->val)
			printf("%s=%s\n", node->key, node->val);
		node = node->next;
	}
}
