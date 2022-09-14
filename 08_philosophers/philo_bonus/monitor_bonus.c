/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoson <yoson@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 23:53:32 by yoson             #+#    #+#             */
/*   Updated: 2022/09/14 18:19:07 by yoson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/wait.h>
#include <pthread.h>
#include "philo_bonus.h"

void	monitor_dead(t_monitor *monitor)
{
	while (monitor->monitor_switch)
	{
		if (waitpid(-1, NULL, WNOHANG) > 0)
		{
			if (!monitor->is_already_killed)
			{
				monitor->is_already_killed = 1;
				philo_kill(monitor);
			}
			monitor->monitor_switch = 0;
			sem_post(monitor->all_eat);
		}
	}
}

void	monitor_all_eat(t_monitor *monitor)
{
	int	i;

	i = -1;
	while (++i < monitor->num_of_philo && monitor->monitor_switch)
		sem_wait(monitor->all_eat);
	monitor->monitor_switch = 0;
	if (!monitor->is_already_killed)
	{
		monitor->is_already_killed = 1;
		philo_kill(monitor);
	}
}

void	monitor(t_monitor *mon, int must_eat)
{
	int			i;
	pthread_t	tid[2];

	if (must_eat > 0)
	{
		if (pthread_create(&tid[0], NULL, (void *)monitor_all_eat, mon) != 0)
			avoid_orphan_kill(mon, mon->num_of_philo, "Thread create failed");
		if (pthread_create(&tid[1], NULL, (void *)monitor_dead, mon) != 0)
			avoid_orphan_kill(mon, mon->num_of_philo, "Thread create failed");
		i = -1;
		while (++i < 2)
			pthread_join(tid[i], NULL);
	}
	else
	{
		if (pthread_create(&tid[0], NULL, (void *)monitor_dead, mon) != 0)
			avoid_orphan_kill(mon, mon->num_of_philo, "Thread create failed");
		pthread_join(tid[0], NULL);
	}
}
