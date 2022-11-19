/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoson <yoson@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 17:13:21 by yoson             #+#    #+#             */
/*   Updated: 2022/11/19 17:25:12 by yoson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	is_quit(int status)
{
	if (!is_normal_terminated(status) && status == 3)
		return (TRUE);
	return (FALSE);
}

int	find_exit_code(int status, int is_sigint)
{
	int		ret;

	if (is_normal_terminated(status))
	{
		if (is_sigint)
			ft_putstr_fd("\n", 1);
		ret = status >> 8;
	}
	else
	{
		if (is_quit(status))
		{
			ft_putstr_fd("Quit: ", 1);
			ft_putnbr_fd(status, 1);
		}
		ret = status + 128;
		ft_putstr_fd("\n", 1);
	}
	return (ret);
}
