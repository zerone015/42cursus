/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   kill_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoson <yoson@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 23:51:50 by yoson             #+#    #+#             */
/*   Updated: 2022/09/13 14:15:35 by yoson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/wait.h>
#include <signal.h>
#include "philo_bonus.h"

void	philo_kill(t_monitor *monitor, pid_t dead)
{
	int	i;

	i = -1;
	while (++i < monitor->num_of_philo && monitor->pid[i] > 0)
	{
		if (monitor->pid[i] == dead)
			continue ;
		kill(monitor->pid[i], SIGTERM);
	}
}

void	avoid_orphan_kill(t_monitor *monitor, int size, char *msg)
{
	int	i;

	i = -1;
	while (++i < size)
		waitpid(monitor->pid[i], NULL, 0);
	philo_kill(monitor, 0);
	error(msg);
}
