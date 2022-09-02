#include "minishell.h"
#include "../../libft/libft.h"

void	builtin_process(t_token *token, t_env *env)
{
	char	**argv;
	char	*join;
	char	*temp;
	t_enode	*node;

	join = ft_strdup("");
	node = token->head->next;
	while (node)
	{
		temp = join;
		join = ft_strjoin(temp, node->str);
		free(temp);
		if (node->next && node->type)
	}
	argv = ft_split(join, ' ');
}
