/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoson <yoson@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 18:58:31 by yoson             #+#    #+#             */
/*   Updated: 2022/08/01 08:46:11 by yoson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H

# include "../libft/libft.h"
# include "get_next_line_bonus.h"

void	pipex(int argc, char *argv[], char *envp[]);
void	here_doc(char *limiter, int argc);
void	read_and_write(char *limiter, int fd[]);
void	child_process(char *argv, char *envp[]);
void	execute(char *argv, char *envp[]);
char	*slash_ignore(char *argv);
char	**parse_envp(char *envp[]);
char	*find_path(char *cmd, char *envp[]);
void	error(char *name, char *content, int status);

#endif
