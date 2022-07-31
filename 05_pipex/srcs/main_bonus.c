/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoson <yoson@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 19:36:53 by yoson             #+#    #+#             */
/*   Updated: 2022/08/01 06:20:27 by yoson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex_bonus.h"
#include <stdlib.h>
#include <unistd.h>

int	main(int argc, char *argv[], char *envp[])
{
	if (argc < 5)
	{
		ft_putstr_fd("Error: Too few arguments\n", STDERR_FILENO);
		return (EXIT_FAILURE);
	}
	pipex(argc, argv, envp);
	return (0);
}
