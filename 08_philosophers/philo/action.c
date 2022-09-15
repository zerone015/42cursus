/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoson <yoson@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 22:27:03 by kijsong           #+#    #+#             */
/*   Updated: 2022/09/15 21:59:03 by yoson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdio.h>
#include "philo.h"

static int	print_action(t_info *info, t_philo *philo, char *msg)
{
	time_t	timestamp;

	if (dead_exists(info) || is_all_eat(info))
	{
		pthread_mutex_unlock(&info->fork[philo->left_fork]);
		pthread_mutex_unlock(&info->fork[philo->right_fork]);
		return (1);
	}
	pthread_mutex_lock(&info->print);
	timestamp = timestamp_in_ms(info->start_time);
	printf(msg, timestamp, philo->id);
	pthread_mutex_unlock(&info->print);
	return (0);
}

static void	dead_check(t_info *info, t_philo *philo, time_t time_to_act)
{
	time_t	now_time;
	time_t	dead_time;

	now_time = timestamp_in_ms(info->start_time);
	if (now_time - philo->last_time + time_to_act > info->time_to_die)
	{
		dead_time = philo->last_time + info->time_to_die;
		if (time_to_act)
			smart_sleep(dead_time - now_time);
		pthread_mutex_lock(&info->dead_mutex);
		if (!info->dead)
		{
			info->dead = 1;
			info->dead_time = dead_time;
			info->dead_philo = philo->id;
		}
		pthread_mutex_unlock(&info->fork[philo->left_fork]);
		pthread_mutex_unlock(&info->fork[philo->right_fork]);
		pthread_mutex_unlock(&info->dead_mutex);
	}
}

static int	eating(t_philo *philo)
{
	t_info	*info;

	info = philo->info;
	pthread_mutex_lock(&info->fork[philo->left_fork]);
	if (print_action(info, philo, "%zu %d has taken a fork\n"))
		return (1);
	pthread_mutex_lock(&info->fork[philo->right_fork]);
	if (print_action(info, philo, "%zu %d has taken a fork\n"))
		return (1);
	dead_check(info, philo, info->time_to_eat);
	if (print_action(info, philo, "%zu %d is eating\n"))
		return (1);
	philo->last_time = timestamp_in_ms(info->start_time);
	smart_sleep(info->time_to_eat);
	(philo->eat_cnt)++;
	set_global_eat_cnt(info, philo);
	pthread_mutex_unlock(&info->fork[philo->left_fork]);
	pthread_mutex_unlock(&info->fork[philo->right_fork]);
	return (0);
}

static int	sleeping(t_philo *philo)
{
	t_info	*info;

	info = philo->info;
	if (print_action(info, philo, "%zu %d is sleeping\n"))
		return (1);
	dead_check(info, philo, info->time_to_sleep);
	smart_sleep(info->time_to_sleep);
	return (0);
}

void	action(t_philo *philo)
{
	t_info	*info;

	info = philo->info;
	if (philo->id % 2)
		smart_sleep(15);
	while (1)
	{
		if (eating(philo) || sleeping(philo))
			return ;
		if (print_action(info, philo, "%zu %d is thinking\n"))
			return ;
	}
}
