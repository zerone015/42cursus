/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoson <yoson@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 22:27:03 by kijsong           #+#    #+#             */
/*   Updated: 2022/09/11 20:57:50 by yoson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include "philo_bonus.h"

static int	dead_check(t_info *info, t_philo *philo, char *msg)
{
	time_t	timestamp;

	sem_wait(info->print);
	timestamp = timestamp_in_ms(info->start_time);
	if (info->dead_time && timestamp > info->dead_time)
	{
		if (info->dead == 1)
		{
			printf("%zu %d died\n", info->dead_time, info->dead_philo);
			info->dead++;
		}
		sem_post(info->fork);
		sem_post(info->fork);
		sem_post(info->print);
		return (1);
	}
	if (!info->dead)
		printf(msg, timestamp, philo->id);
	sem_post(info->print);
	return (0);
}

static void	ft_usleep(t_info *info, t_philo *philo, time_t time_to_act)
{
	time_t	before_act;
	time_t	after_act;

	before_act = timestamp_in_ms(info->start_time);
	after_act = before_act - philo->last_time + time_to_act;
	sem_wait(info->die);
	if (!info->dead && after_act > info->time_to_die)
	{
		info->dead = 1;
		info->dead_philo = philo->id;
		info->dead_time = philo->last_time + info->time_to_die;
	}
	sem_post(info->die);
	smart_sleep(time_to_act);
}

static int	eating(t_philo *philo)
{
	t_info	*info;

	info = philo->info;
	sem_wait(info->fork);
	sem_wait(info->fork);
	if (dead_check(info, philo, "%zu %d has taken a fork\n"))
		return (1);
	if (dead_check(info, philo, "%zu %d is eating\n"))
		return (1);
	ft_usleep(info, philo, info->time_to_eat);
	philo->last_time = timestamp_in_ms(info->start_time);
	(philo->eat_cnt)++;
	if (philo->eat_cnt == info->must_eat)
		sem_wait(info->all_eat);
	sem_post(info->fork);
	sem_post(info->fork);
	return (0);
}

static int	sleeping(t_philo *philo)
{
	t_info	*info;

	info = philo->info;
	if (dead_check(info, philo, "%zu %d is sleeping\n"))
		return (1);
	ft_usleep(info, philo, info->time_to_sleep);
	return (0);
}

void	action(t_philo *philo)
{
	t_info	*info;

	info = philo->info;
	unlink_sem();
	if (philo->id % 2)
		smart_sleep(15);
	while (1)
	{
		if (eating(philo) || sleeping(philo))
			exit(0);
		if (dead_check(info, philo, "%zu %d is thinking\n"))
			exit(0);
	}
}
