/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoson <yoson@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 22:27:03 by kijsong           #+#    #+#             */
/*   Updated: 2022/09/16 21:49:00 by yoson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include "philo_bonus.h"

static void	print_action(t_info *info, t_philo *philo, char *msg)
{
	time_t	timestamp;

	sem_wait(info->print);
	timestamp = timestamp_in_ms(info->start_time);
	printf(msg, timestamp, philo->id);
	sem_post(info->print);
}

static void	eating(t_philo *philo)
{
	t_info	*info;

	info = philo->info;
	sem_wait(info->fork);
	print_action(info, philo, "%zu %d has taken a fork\n");
	sem_wait(info->fork);
	print_action(info, philo, "%zu %d has taken a fork\n");
	print_action(info, philo, "%zu %d is eating\n");
	sem_wait(info->print);
	philo->last_time = timestamp_in_ms(info->start_time);
	sem_post(info->print);
	smart_sleep(info->time_to_eat);
	(philo->eat_cnt)++;
	if (philo->eat_cnt == info->must_eat)
		sem_post(info->all_eat);
	sem_post(info->fork);
	sem_post(info->fork);
}

static void	sleeping(t_philo *philo)
{
	t_info	*info;

	info = philo->info;
	print_action(info, philo, "%zu %d is sleeping\n");
	smart_sleep(info->time_to_sleep);
}

static void	monitor_dead(t_philo *philo)
{
	t_info	*info;
	time_t	now_time;

	info = philo->info;
	while (1)
	{
		sem_wait(info->print);
		now_time = timestamp_in_ms(info->start_time);
		if (now_time > philo->last_time + info->time_to_die)
		{
			printf("%zu %d died\n", now_time, philo->id);
			exit(1);
		}
		sem_post(info->print);
	}
}

void	action(t_philo *philo)
{
	t_info		*info;
	pthread_t	tid;

	info = philo->info;
	if (pthread_create(&tid, NULL, (void *)monitor_dead, philo) != 0)
		exit(1);
	pthread_detach(tid);
	if (philo->id % 2)
		smart_sleep(40);
	while (1)
	{
		eating(philo);
		sleeping(philo);
		print_action(info, philo, "%zu %d is thinking\n");
	}
}
