/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wildcard.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kijsong <kijsong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 09:02:24 by kijsong           #+#    #+#             */
/*   Updated: 2022/12/21 19:06:13 by kijsong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static void	get_execs(t_lst **execs)
{
	int				index;
	char			**paths;
	DIR				*dir;
	struct dirent	*file;

	*execs = NULL;
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
	ft_free(paths);
}

static int	is_exec(char *word, t_lst *execs)
{
	while (execs)
	{
		if (word == execs->content)
			return (TRUE);
		execs = execs->next;
	}
	return (FALSE);
}

static void	clear_wildcard(t_lst *execs, DIR *dir)
{
	ft_lstclear(&execs, free);
	closedir(dir);
}

void	convert_wildcard(char *word, t_lst **argv)
{
	char			cwd[PATH_MAX];
	t_lst			*execs;
	DIR				*dir;
	struct dirent	*file;

	get_execs(&execs);
	if (is_exec(word, execs) || !ft_strchr(word, '*'))
	{
		ft_lstadd_back(argv, ft_lstnew(ft_strdup(word)));
		ft_lstclear(&execs, free);
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
	clear_wildcard(execs, dir);
}
