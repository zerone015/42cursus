/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoson <yoson@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 21:01:12 by yoson             #+#    #+#             */
/*   Updated: 2022/09/10 15:40:14 by yoson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/time.h>
#include "philo.h"

static void	init_philo(t_info *info)
{
	int	i;

	i = -1;
	while (++i < info->num_of_philo)
	{
		info->philo[i].id = i + 1;
		info->philo[i].left_fork = i;
		info->philo[i].right_fork = (i + 1) % info->num_of_philo;
		info->philo[i].eat_cnt = 0;
		// info->philo[i].last_time = info->start_time;
		info->philo[i].last_time = 0;
		info->philo[i].info = info;
	}
}

static void	init_mutex(t_info *info)
{
	int	i;

	i = -1;
	while (++i < info->num_of_philo)
	{
		if (pthread_mutex_init(&info->fork[i], NULL) != 0)
			error("Mutex initialization failed");
	}
	if (pthread_mutex_init(&info->print, NULL) != 0)
		error("Mutex initialization failed");
	if (pthread_mutex_init(&info->die, NULL) != 0)
		error("Mutex initialization failed");
}

void	init_info(t_info *info, char *argv[])
{
	struct timeval	start;

	info->num_of_philo = ft_atoi(argv[1]);
	info->time_to_die = ft_atoi(argv[2]);
	info->time_to_eat = ft_atoi(argv[3]);
	info->time_to_sleep = ft_atoi(argv[4]);
	info->must_eat = 0;
	if (argv[5])
		info->must_eat = ft_atoi(argv[5]);
	info->dead = 0;
	info->dead_time = 0;
	info->all_eat = 0;
	gettimeofday(&start, NULL);
	info->start_time = start.tv_sec * 1000 + start.tv_usec / 1000;
	info->fork = safe_malloc(sizeof(pthread_mutex_t) * info->num_of_philo);
	init_mutex(info);
	info->philo = safe_malloc(sizeof(t_philo) * info->num_of_philo);
	init_philo(info);
}
