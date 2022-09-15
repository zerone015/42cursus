/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoson <yoson@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 16:39:18 by yoson             #+#    #+#             */
/*   Updated: 2022/09/15 20:49:46 by yoson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "philo.h"

void	set_global_eat_cnt(t_info *info, t_philo *philo)
{
	if (philo->eat_cnt == info->must_eat)
	{
		pthread_mutex_lock(&info->eat_mutex);
		(info->eat_cnt)++;
		pthread_mutex_unlock(&info->eat_mutex);
	}
}

int	set_dead(time_t dead_time, t_philo *philo, t_info *info, time_t delay)
{
	smart_sleep(delay);
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
	return (1);
}

int	is_all_eat(t_info *info)
{
	int	ret;

	if (!info->must_eat)
		return (0);
	pthread_mutex_lock(&info->eat_mutex);
	if (info->eat_cnt == info->num_of_philo)
		ret = 1;
	else
		ret = 0;
	pthread_mutex_unlock(&info->eat_mutex);
	return (ret);
}

int	dead_exists(t_info *info)
{
	int	ret;

	pthread_mutex_lock(&info->dead_mutex);
	if (info->dead)
	{
		if (info->dead == 1)
		{
			printf("%zu %d died\n", info->dead_time, info->dead_philo);
			info->dead++;
		}
		ret = 1;
	}
	else
		ret = 0;
	pthread_mutex_unlock(&info->dead_mutex);
	return (ret);
}
