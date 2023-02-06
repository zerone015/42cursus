/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoson <yoson@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 18:58:31 by yoson             #+#    #+#             */
/*   Updated: 2022/11/10 17:21:36 by yoson            ###   ########.fr       */
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
void	ft_strerror(void);
char	*ft_strchr(const char *str, int c);

#endif
