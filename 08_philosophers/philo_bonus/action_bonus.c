/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoson <yoson@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 22:27:03 by kijsong           #+#    #+#             */
/*   Updated: 2022/09/13 11:00:23 by yoson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "philo_bonus.h"

static void	dead_check(t_info *info, t_philo *philo, char *msg)
{
	time_t	timestamp;

	if (philo->dead == 1)
	{
		printf("%zu %d died\n", philo->dead_time, philo->id);
		exit(0);
	}
	sem_wait(info->print);
	timestamp = timestamp_in_ms(info->start_time);
	printf(msg, timestamp, philo->id);
	sem_post(info->print);
}

static void	ft_usleep(t_info *info, t_philo *philo, time_t time_to_act)
{
	time_t	before_act;
	time_t	after_act;

	before_act = timestamp_in_ms(info->start_time);
	after_act = before_act - philo->last_time + time_to_act;
	if (after_act > info->time_to_die)
	{
		philo->dead = 1;
		philo->dead_time = philo->last_time + info->time_to_die;
		smart_sleep(philo->dead_time - before_act);
		sem_wait(info->print);
	}
	if (!philo->dead)
		smart_sleep(time_to_act);
}

static void	eating(t_philo *philo)
{
	t_info	*info;

	info = philo->info;
	sem_wait(info->fork);
	sem_wait(info->fork);
	dead_check(info, philo, "%zu %d has taken a fork\n");
	dead_check(info, philo, "%zu %d is eating\n");
	ft_usleep(info, philo, info->time_to_eat);
	philo->last_time = timestamp_in_ms(info->start_time);
	(philo->eat_cnt)++;
	if (philo->eat_cnt == info->must_eat)
		sem_wait(info->all_eat);
	sem_post(info->fork);
	sem_post(info->fork);
}

static void	sleeping(t_philo *philo)
{
	t_info	*info;

	info = philo->info;
	dead_check(info, philo, "%zu %d is sleeping\n");
	ft_usleep(info, philo, info->time_to_sleep);
}

void	action(t_philo *philo)
{
	t_info	*info;

	info = philo->info;
	if (philo->id % 2)
		smart_sleep(40);
	while (1)
	{
		eating(philo);
		sleeping(philo);
		dead_check(info, philo, "%zu %d is thinking\n");
	}
}
