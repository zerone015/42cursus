/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoson <yoson@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 23:53:32 by yoson             #+#    #+#             */
/*   Updated: 2022/09/13 00:23:17 by yoson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/wait.h>
#include <pthread.h>
#include "philo_bonus.h"

void	macro_all_eat(t_info *info)
{
	while (info->shared_flag)
	{
		sem_wait(info->all_eat);
		info->shared_var++;
		sem_post(info->all_eat);
	}
}

void	monitor_dead(t_info *info)
{
	while (info->shared_flag)
	{
		if (waitpid(-1, NULL, WNOHANG) > 0)
		{
			philo_kill(info);
			info->shared_flag = 0;
		}
	}
}

void	monitor_all_eat(t_info *info)
{
	int	temp;

	sem_wait(info->all_eat);
	while (info->shared_flag)
	{
		temp = info->shared_var;
		smart_sleep(info->num_of_philo);
		if (info->shared_var == temp)
		{
			philo_kill(info);
			info->shared_flag = 0;
		}
	}
	sem_post(info->all_eat);
}

void	monitor(t_info *info)
{
	int			i;
	pthread_t	tid[3];

	if (pthread_create(&tid[0], NULL, (void *)macro_all_eat, info) != 0)
		avoid_orphan_kill(info, info->num_of_philo, "Thread create failed");
	if (pthread_create(&tid[1], NULL, (void *)monitor_all_eat, info) != 0)
		avoid_orphan_kill(info, info->num_of_philo, "Thread create failed");
	if (pthread_create(&tid[2], NULL, (void *)monitor_dead, info) != 0)
		avoid_orphan_kill(info, info->num_of_philo, "Thread create failed");
	i = -1;
	while (++i < 3)
		pthread_join(tid[i], NULL);
}
