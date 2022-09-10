/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kijsong <kijsong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 22:27:03 by kijsong           #+#    #+#             */
/*   Updated: 2022/09/10 22:37:11 by kijsong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdio.h>
#include "philo.h"

static int	dead_check(t_info *info, t_philo *philo, char *msg)
{
	size_t	timestamp;

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

static void	ft_usleep(t_info *info, t_philo *philo, size_t time_to_act)
{
	size_t	before_act;
	size_t	action_time;

	before_act = timestamp_in_ms(info->start_time);
	action_time = before_act - philo->last_time + time_to_act;
	pthread_mutex_lock(&info->die);
	if (!info->dead && action_time > info->time_to_die)
	{
		info->dead = 1;
		info->dead_philo = philo->id;
		info->dead_time = philo->last_time + info->time_to_die;
	}
	pthread_mutex_unlock(&info->die);
	msleep(time_to_act);
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
		msleep(15);
	while (!info->all_eat)
	{
		if (eating(philo) || sleeping(philo))
			return ;
		if (dead_check(info, philo, "%zu %d is thinking\n"))
			return ;
	}
}
