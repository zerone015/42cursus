/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoson <yoson@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 22:27:03 by kijsong           #+#    #+#             */
/*   Updated: 2022/09/17 02:17:30 by yoson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdio.h>
#include "philo.h"

static int	print_action(t_info *info, t_philo *philo, char *msg)
{
	time_t	timestamp;

	pthread_mutex_lock(&info->print);
	if (info->dead || (info->must_eat && info->eat_cnt == info->num_of_philo))
	{
		pthread_mutex_unlock(&info->fork[philo->left_fork]);
		pthread_mutex_unlock(&info->fork[philo->right_fork]);
		pthread_mutex_unlock(&info->print);
		return (-1);
	}
	timestamp = timestamp_in_ms(info->start_time);
	printf(msg, timestamp, philo->id);
	pthread_mutex_unlock(&info->print);
	return (0);
}

void	set_global_eat_cnt(t_info *info, t_philo *philo)
{
	if (philo->eat_cnt == info->must_eat)
	{
		pthread_mutex_lock(&info->print);
		(info->eat_cnt)++;
		pthread_mutex_unlock(&info->print);
	}
}

static int	eating(t_philo *philo)
{
	t_info	*info;

	info = philo->info;
	pthread_mutex_lock(&info->fork[philo->left_fork]);
	if (print_action(info, philo, "%zu %d has taken a fork\n"))
		return (-1);
	pthread_mutex_lock(&info->fork[philo->right_fork]);
	if (print_action(info, philo, "%zu %d has taken a fork\n"))
		return (-1);
	if (print_action(info, philo, "%zu %d is eating\n"))
		return (-1);
	pthread_mutex_lock(&info->print);
	philo->last_time = timestamp_in_ms(info->start_time);
	pthread_mutex_unlock(&info->print);
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
		return (-1);
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
