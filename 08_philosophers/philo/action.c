/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoson <yoson@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 22:27:03 by kijsong           #+#    #+#             */
/*   Updated: 2022/09/13 02:57:56 by yoson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdio.h>
#include "philo.h"

static int	dead_check(t_info *info, t_philo *philo, char *msg)
{
	time_t	timestamp;

	pthread_mutex_lock(&info->print);
	timestamp = timestamp_in_ms(info->start_time);
	if (info->dead_time && timestamp > info->dead_time)
	{
		if (info->dead == 1)
		{
			printf("%zu %d died\n", info->dead_time, info->dead_philo);
			info->dead++;
		}
		pthread_mutex_unlock(&info->fork[philo->left_fork]);
		pthread_mutex_unlock(&info->fork[philo->right_fork]);
		pthread_mutex_unlock(&info->print);
		return (1);
	}
	if (!info->dead)
		printf(msg, timestamp, philo->id);
	pthread_mutex_unlock(&info->print);
	return (0);
}

static void	ft_usleep(t_info *info, t_philo *philo, time_t time_to_act)
{
	time_t	before_act;
	time_t	after_act;

	before_act = timestamp_in_ms(info->start_time);
	after_act = before_act - philo->last_time + time_to_act;
	pthread_mutex_lock(&info->dead_mutex);
	if (!info->dead && after_act > info->time_to_die)
	{
		info->dead = 1;
		info->dead_philo = philo->id;
		info->dead_time = philo->last_time + info->time_to_die;
	}
	pthread_mutex_unlock(&info->dead_mutex);
	smart_sleep(time_to_act);
}

static int	eating(t_philo *philo)
{
	t_info	*info;

	info = philo->info;
	pthread_mutex_lock(&info->fork[philo->left_fork]);
	pthread_mutex_lock(&info->fork[philo->right_fork]);
	if (dead_check(info, philo, "%zu %d has taken a fork\n"))
		return (1);
	if (dead_check(info, philo, "%zu %d is eating\n"))
		return (1);
	ft_usleep(info, philo, info->time_to_eat);
	philo->last_time = timestamp_in_ms(info->start_time);
	(philo->eat_cnt)++;
	pthread_mutex_unlock(&info->fork[philo->left_fork]);
	pthread_mutex_unlock(&info->fork[philo->right_fork]);
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
	if (philo->id % 2)
		smart_sleep(15);
	while (!info->all_eat)
	{
		if (eating(philo) || sleeping(philo))
			return ;
		if (dead_check(info, philo, "%zu %d is thinking\n"))
			return ;
	}
}
