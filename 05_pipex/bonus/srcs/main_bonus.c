/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoson <yoson@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 04:06:27 by yoson             #+#    #+#             */
/*   Updated: 2022/11/01 05:04:49 by yoson            ###   ########.fr       */
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
	if (!paths)
	{
		perror("pipex: ");
		return (EXIT_FAILURE);
	}
	pipex(argc, argv, envp, paths);
	unlink("/tmp/.here_doc");
	return (0);
}
