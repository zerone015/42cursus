/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoson <yoson@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 19:36:53 by yoson             #+#    #+#             */
/*   Updated: 2022/07/30 08:00:26 by yoson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"
#include <stdlib.h>
#include <unistd.h>

int	main(int argc, char *argv[], char *envp[])
{
	if (argc > 5)
	{
		ft_putstr_fd("Error: Too many arguments\n", STDERR_FILENO);
		return (EXIT_FAILURE);
	}
	if (argc < 5)
	{
		ft_putstr_fd("Error: Too few arguments\n", STDERR_FILENO);
		return (EXIT_FAILURE);
	}
	pipex(argv, envp);
	return (0);
}
