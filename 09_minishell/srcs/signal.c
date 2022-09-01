/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoson <yoson@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 14:31:54 by kijsong           #+#    #+#             */
/*   Updated: 2022/09/01 21:47:29 by yoson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include "../libft/libft.h"

void	handler(int signum)
{
	if (signum == SIGINT)
	{
		ft_putendl_fd("exit", 1);
		exit(0);
	}
	// else if (signum == SIGQUIT)
	
}

void	safe_signal(int signum, void (*handler)(int))
{
	if (signal(signum, handler) == SIG_ERR)
		ft_perror(NULL);
}

void	receive_signal(void)
{
	safe_signal(SIGINT, handler);
	// safe_signal(SIGQUIT, handler);
}
