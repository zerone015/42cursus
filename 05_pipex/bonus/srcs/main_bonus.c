/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: son-yeong-won <son-yeong-won@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 04:06:27 by yoson             #+#    #+#             */
/*   Updated: 2023/02/07 02:16:25 by son-yeong-w      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"
#include <stdlib.h>
#include <stdio.h>

int	main(int argc, char *argv[], char *envp[])
{
	char	**paths;

	if (argc < 5 || (is_heredoc(argv[1]) && argc < 6))
	{
		ft_putstr_fd("Error: Too few arguments\n", STDERR_FILENO);
		return (EXIT_FAILURE);
	}
	paths = parse_paths(envp);
	pipex(argc, argv, envp, paths);
	unlink("/tmp/.here_doc");
	return (0);
}
