/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoson <yoson@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 18:58:31 by yoson             #+#    #+#             */
/*   Updated: 2022/07/30 04:46:52 by yoson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "../libft/libft.h"

typedef struct s_info
{
	char	*infile;
	char	*outfile;
	char	**cmds;
	char	**paths;
}	t_info;

void	pipex(t_info *info, char **envp);
void	child_process(t_info *info, int *fd, char **envp);
void	parent_process(t_info *info, int *fd, char **envp);

void	parse_info(t_info *info, char **argv, char **envp);
char	**parse_cmd(char **argv);
char	**parse_path(char **envp);

char	*find_path(char **paths, char *cmd);
void	error(void);
void	command_not_found(char *cmd);

#endif
