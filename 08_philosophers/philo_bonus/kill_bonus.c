/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   kill_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoson <yoson@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 23:51:50 by yoson             #+#    #+#             */
/*   Updated: 2022/09/13 12:01:34 by yoson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/wait.h>
#include <signal.h>
#include "philo_bonus.h"

void	philo_kill(t_info *info, pid_t dead)
{
	int	i;

	i = -1;
	while (++i < info->num_of_philo && info->pid[i] > 0)
	{
		if (info->pid[i] == dead)
			continue ;
		kill(info->pid[i], SIGTERM);
	}
}

void	avoid_orphan_kill(t_info *info, int size, char *msg)
{
	int	i;

	i = -1;
	while (++i < size)
		waitpid(info->pid[i], NULL, 0);
	philo_kill(info, 0);
	error(msg);
}
