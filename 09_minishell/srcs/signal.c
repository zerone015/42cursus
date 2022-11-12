/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kijsong <kijsong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 14:31:54 by kijsong           #+#    #+#             */
/*   Updated: 2022/11/12 21:36:38 by yoson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <term.h>
#include <readline/readline.h>
#include <unistd.h>
#include "../libft/libft.h"
#include "../includes/minishell.h"

void	handler(int signum)
{
	if (signum == SIGINT)
	{
		ft_putchar_fd('\n', STDOUT_FILENO);
		rl_replace_line("", 1);
		if (rl_on_new_line() == -1)
			ft_perror(NULL);
		rl_redisplay();
	}
}

void	safe_signal(int signum, void (*handler)(int))
{
	if (signal(signum, handler) == SIG_ERR)
		ft_perror(NULL);
}

void	echoctl(int flag)
{
	struct termios	term;

	if (tcgetattr(STDOUT_FILENO, &term) == -1)
		ft_perror(NULL);
	if (flag)
		term.c_lflag |= ECHOCTL;
	else
		term.c_lflag &= ~(ECHOCTL);
	if (tcsetattr(STDOUT_FILENO, TCSANOW, &term) == -1)
		ft_perror(NULL);
}

void	set_signal(int status)
{
	if (status == CHILD)
	{
		safe_signal(SIGINT, SIG_DFL);
		safe_signal(SIGQUIT, SIG_DFL);
	}
	else if (status == PARENT)
	{
		echoctl(FALSE);
		safe_signal(SIGINT, handler);
		safe_signal(SIGQUIT, SIG_IGN);
	}
}
