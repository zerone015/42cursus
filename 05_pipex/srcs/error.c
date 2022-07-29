/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoson <yoson@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/30 06:12:26 by yoson             #+#    #+#             */
/*   Updated: 2022/07/30 08:01:35 by yoson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void	error(void)
{
	perror("Error");
	exit(EXIT_FAILURE);
}

void	command_not_found(char *cmd)
{
	ft_putstr_fd("command not found: ", STDERR_FILENO);
	ft_putstr_fd(cmd, STDERR_FILENO);
	ft_putstr_fd("\n", STDERR_FILENO);
	exit(127);
}
