/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoson <yoson@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 18:58:31 by yoson             #+#    #+#             */
/*   Updated: 2022/08/01 05:06:29 by yoson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "../libft/libft.h"

void	pipex(char *argv[], char *envp[]);
void	child_process(char *argv[], char *envp[], int fd[]);
void	parent_process(char *argv[], char *envp[], int fd[]);
void	execute(char *argv, char *envp[]);
char	*slash_ignore(char *argv);
char	**parse_envp(char *envp[]);
char	*find_path(char *cmd, char *envp[]);
void	error(char *name, char *content, int status);

#endif
