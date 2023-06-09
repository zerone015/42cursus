/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: son-yeong-won <son-yeong-won@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 18:58:31 by yoson             #+#    #+#             */
/*   Updated: 2023/02/07 02:13:55 by son-yeong-w      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H

# define TRUE	1
# define FALSE	0

# include <unistd.h>
# include "libft.h"

void	pipex(int argc, char *argv[], char *envp[], char *paths[]);
void	execute(char *arg, char *envp[], char *paths[]);

char	**parse_paths(char *envp[]);
int		is_heredoc(char *arg);
void	here_doc(char *limiter);
char	*get_next_line(int fd);

void	command_not_found(char *cmd);
void	ft_perror(char *input, int exit_code);
char	*ft_strchr(const char *str, int c);

#endif
