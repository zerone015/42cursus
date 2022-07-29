/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoson <yoson@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/30 02:43:52 by yoson             #+#    #+#             */
/*   Updated: 2022/07/30 04:35:26 by yoson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"
#include <stdlib.h>
#include <stdio.h>

void	error(void)
{
	perror("Error");
	exit(EXIT_FAILURE);
}

void	command_not_found(char *cmd)
{
	ft_putstr_fd("command not found: ", 2);
	ft_putstr_fd(cmd, 2);
	ft_putstr_fd("\n", 2);
	exit(127);
}
