/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kijsong <kijsong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 14:31:54 by kijsong           #+#    #+#             */
/*   Updated: 2022/09/03 17:33:41 by kijsong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <term.h>
#include <readline/readline.h>
#include "../libft/libft.h"

void	handler(int signum)
{
	if (signum == SIGINT)
	{
		ft_putchar_fd('\n', 2);
		rl_replace_line("", 0);
		if (rl_on_new_line() == -1)
			exit(1);
		rl_redisplay();
	}
	// else if (signum == SIGQUIT)
	// {

	// }
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

// void	echoctl(void)
// {
// 	struct termios	term;
// 	int				fd;

// 	fd = tcgetattr(int, struct termios *)
// }
