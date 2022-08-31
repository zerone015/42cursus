/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoson <yoson@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 14:31:54 by kijsong           #+#    #+#             */
/*   Updated: 2022/08/31 15:06:33 by yoson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include "../libft/libft.h"

void	handler(int signum)
{
	if (signum == SIGINT)

	else if (signum == SIGQUIT)
	
}

void	safe_signal(int signum, void (*handler)(int))
{
	if (signal(signum, handler) == SIG_ERR)
		ft_perror(NULL);
}

void	receive_signal(void)
{
	safe_signal(SIGINT, handler);
	safe_signal(SIGQUIT, handler);
	// safe_signal(SIGKILL, handler);
}
