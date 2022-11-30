/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wildcard.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kijsong <kijsong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 09:02:24 by kijsong           #+#    #+#             */
/*   Updated: 2022/11/30 16:16:45 by kijsong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	get_execs(t_lst **execs)
{
	int				index;
	char			**paths;
	DIR				*dir;
	struct dirent	*file;

	paths = ft_split(getenv("PATH"), ':');
	index = 0;
	while (paths[index])
	{
		dir = opendir(paths[index]);
		while (dir)
		{
			file = readdir(dir);
			if (!file)
				break ;
			ft_lstadd_back(execs, ft_lstnew(ft_strdup(file->d_name)));
		}
		closedir(dir);
		index++;
	}
}

int	is_exec(char *word, t_lst *execs)
{
	while (execs)
	{
		if (word == execs->content)
			return (TRUE);
		execs = execs->next;
	}
	return (FALSE);
}

void	convert_wildcard(char *word, t_lst **argv)
{
	char			cwd[PATH_MAX];
	t_lst			*execs;
	DIR				*dir;
	struct dirent	*file;

	execs = NULL;
	get_execs(&execs);
	if (is_exec(word, execs) || !ft_strchr(word, '*'))
	{
		ft_lstadd_back(argv, ft_lstnew(word));
		return ;
	}
	getcwd(cwd, sizeof(cwd));
	dir = opendir(cwd);
	while (dir)
	{
		file = readdir(dir);
		if (!file)
			break ;
		if (!ft_strcmp(file->d_name, ".") || !ft_strcmp(file->d_name, ".."))
			continue ;
		if (match_wildcard(word, file))
			ft_lstadd_back(argv, ft_lstnew(ft_strdup(file->d_name)));
	}
	closedir(dir);
}
