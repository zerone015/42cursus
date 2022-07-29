/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoson <yoson@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 19:36:53 by yoson             #+#    #+#             */
/*   Updated: 2022/07/30 04:35:35 by yoson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"
#include <stdlib.h>

int	main(int argc, char **argv, char **envp)
{
	t_info	info;

	if (argc != 5)
	{
		ft_putstr_fd("Error: bad arguments\n", 2);
		return (EXIT_FAILURE);
	}
	parse_info(&info, argv, envp);
	pipex(&info, envp);
	return (0);
}
