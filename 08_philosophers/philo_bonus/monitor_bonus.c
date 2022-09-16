/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoson <yoson@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 23:53:32 by yoson             #+#    #+#             */
/*   Updated: 2022/09/16 21:18:35 by yoson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/wait.h>
#include <pthread.h>
#include "philo_bonus.h"

static void	monitor_dead(t_monitor *monitor)
{
	while (1)
	{
		sem_wait(monitor->monitor_sem);
		if (monitor->is_exit)
		{
			sem_post(monitor->monitor_sem);
			return ;
		}
		sem_post(monitor->monitor_sem);
		if (waitpid(-1, NULL, WNOHANG) > 0)
		{
			philo_kill(monitor);
			sem_wait(monitor->monitor_sem);
			monitor->is_exit = 1;
			sem_post(monitor->all_eat);
			sem_post(monitor->monitor_sem);
		}
	}
}

static void	monitor_all_eat(t_monitor *monitor)
{
	int	i;

	i = -1;
	while (++i < monitor->num_of_philo)
	{
		sem_wait(monitor->monitor_sem);
		if (monitor->is_exit)
		{
			sem_post(monitor->monitor_sem);
			return ;
		}
		sem_post(monitor->monitor_sem);
		sem_wait(monitor->all_eat);
	}
	philo_kill(monitor);
	sem_wait(monitor->monitor_sem);
	monitor->is_exit = 1;
	sem_post(monitor->monitor_sem);
}

void	monitor(t_monitor *mon, int must_eat)
{
	pthread_t	tid;

	if (must_eat)
	{
		if (pthread_create(&tid, NULL, (void *)monitor_all_eat, mon) != 0)
			avoid_orphan_kill(mon, mon->num_of_philo, "pthread_create failed");
		pthread_detach(tid);
	}
	monitor_dead(mon);
}
