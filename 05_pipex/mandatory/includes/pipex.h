/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoson <yoson@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 18:58:31 by yoson             #+#    #+#             */
/*   Updated: 2022/11/01 02:12:06 by yoson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# define TRUE	1
# define FALSE	0

# include "libft.h"

void	pipex(char *argv[], char *envp[], char *paths[]);
void	execute(char *arg, char *envp[], char *paths[]);
void	command_not_found(char *input);
void	ft_perror(char *input, int exit_code);
void	ft_strerror(void);

#endif
