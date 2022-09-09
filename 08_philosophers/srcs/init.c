/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoson <yoson@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 21:01:12 by yoson             #+#    #+#             */
/*   Updated: 2022/09/09 21:47:31 by yoson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/time.h>
#include "philosophers.h"

static void	init_philo(t_info *info)
{
	int	i;

	i = 0;
	while (++i <= info->num_of_phil)
	{
		info->philo[i].id = i;
		info->philo[i].left_fork = i;
		info->philo[i].right_fork = i % info->num_of_phil + 1;
		info->philo[i].eat_cnt = 0;
		info->philo[i].last_time = info->start_time;
		info->philo[i].info = info;
	}
}

t_info	*init_info(char *argv[])
{
	int				i;
	t_info			*info;
	struct timeval	start;

	info = safe_malloc(sizeof(t_info));
	info->num_of_phil = ft_atoi(argv[1]);
	info->time_to_die = ft_atoi(argv[2]);
	info->time_to_eat = ft_atoi(argv[3]);
	info->time_to_sleep = ft_atoi(argv[4]);
	info->must_eat = 0;
	if (argv[5])
		info->must_eat = ft_atoi(argv[5]);
	info->philo = safe_malloc(sizeof(t_philo) * (info->num_of_phil + 1));
	info->fork = safe_malloc(sizeof(pthread_mutex_t) * (info->num_of_phil + 1));
	i = 0;
	while (++i <= info->num_of_phil)
	{
		if (pthread_mutex_init(&info->fork[i], NULL) != 0)
			error("Mutex initialization failed");
	}
	if (pthread_mutex_init(&info->print, NULL) != 0)
			error("Mutex initialization failed");
	gettimeofday(&start, NULL);
	info->start_time = start.tv_sec * 1000 + start.tv_usec / 1000;
	init_philo(info);
	return (info);
}
