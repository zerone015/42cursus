/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoson <yoson@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 23:53:32 by yoson             #+#    #+#             */
/*   Updated: 2022/09/13 12:11:44 by yoson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/wait.h>
#include <pthread.h>
#include "philo_bonus.h"

void	monitor_dead(t_info *info)
{
	pid_t	pid;

	while (info->monitor_switch)
	{
		pid = waitpid(-1, NULL, WNOHANG);
		if (pid > 0)
		{
			sem_wait(info->kill);
			if (!info->is_allkill)
			{
				info->is_allkill = 1;
				sem_post(info->kill);
				philo_kill(info, pid);
			}
			info->monitor_switch = 0;
			sem_post(info->all_eat);
		}
	}
}

void	monitor_all_eat(t_info *info)
{
	int	i;

	i = -1;
	while (++i < info->num_of_philo && info->monitor_switch)
		sem_wait(info->all_eat);
	info->monitor_switch = 0;
	sem_wait(info->kill);
	if (!info->is_allkill)
	{
		info->is_allkill = 1;
		sem_post(info->kill);
		philo_kill(info, 0);
	}
}

void	monitor(t_info *info)
{
	int			i;
	pthread_t	tid[2];

	if (info->must_eat > 0)
	{
		if (pthread_create(&tid[0], NULL, (void *)monitor_all_eat, info) != 0)
			avoid_orphan_kill(info, info->num_of_philo, "Thread create failed");
		if (pthread_create(&tid[1], NULL, (void *)monitor_dead, info) != 0)
			avoid_orphan_kill(info, info->num_of_philo, "Thread create failed");
		i = -1;
		while (++i < 2)
			pthread_join(tid[i], NULL);
	}
	else
	{
		if (pthread_create(&tid[0], NULL, (void *)monitor_dead, info) != 0)
			avoid_orphan_kill(info, info->num_of_philo, "Thread create failed");
		pthread_join(tid[0], NULL);
	}
}
