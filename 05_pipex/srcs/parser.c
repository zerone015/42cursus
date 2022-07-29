/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoson <yoson@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/30 03:28:35 by yoson             #+#    #+#             */
/*   Updated: 2022/07/30 04:53:04 by yoson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"
#include <stdlib.h>

char	**parse_cmd(char **argv)
{
	char	**cmds;
	size_t	head;
	int		i;

	cmds = (char **) malloc(sizeof(char *) * 3);
	if (!cmds)
		return (NULL);
	i = 2;
	while (i < 4)
	{
		if (ft_strchr(argv[i], '/'))
		{
			head = ft_strrchr(argv[i], '/') - argv[i] + 1;
			cmds[i - 2] = ft_substr(argv[i], head, ft_strlen(argv[i]));
		}
		else
			cmds[i - 2] = ft_strdup(argv[i]);
		if (!cmds[i - 2] || cmds[i - 2][0] == '\0')
			return (NULL);
		i++;
	}
	cmds[i - 2] = NULL;
	return (cmds);
}

char	**parse_path(char **envp)
{
	char	**paths;
	int		i;

	i = 0;
	while (ft_strnstr(envp[i], "PATH", 4) == NULL)
		i++;
	paths = ft_split(envp[i] + 5, ':');
	return (paths);
}

void	parse_info(t_info *info, char **argv, char **envp)
{
	info->cmds = parse_cmd(argv);
	if (!info->cmds)
		error();
	info->paths = parse_path(envp);
	if (!info->paths)
		error();
	info->infile = argv[1];
	info->outfile = argv[4];
}
