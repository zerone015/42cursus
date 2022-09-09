/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoson <yoson@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 16:10:18 by yoson             #+#    #+#             */
/*   Updated: 2022/09/09 13:59:20 by yoson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h> //gettimeofday
#include <sys/time.h> //gettimeofdady
#include <stdio.h> //test
#include "philosophers.h"

// void	eat(t_info *info, int id)
// {
// 	t_philo	philo;

// 	philo = info->philo[info->philo.id];
// 	if (info->fork[philo.id] && info->fork[phi])
// 	pthread_mutex_lock(info->mutex);
// 	eat;
// 	pthread_mutex_unlock(info->mutex);
// }

void	action(t_info *info)
{
	int	id;
	int	cnt_eat;

	id = info->id;
	printf("%d \n", id);
	cnt_eat = 0;
	if (cnt_eat >= 2)
		exit(0);
}

void	philosophers(t_info *info)
{
	int	i;

	i = 1;
	while (i <= info->num_of_phil)
	{
		info->id = i;
		pthread_create(&info->thread, NULL, (void *)action, info);
		i += 2;
		usleep(100);
	}
	usleep(info->time_to_eat);
	i = 2;
	while (i <= info->num_of_phil)
	{
		info->id = i;
		pthread_create(&info->thread, NULL, (void *)action, info);
		i += 2;
		usleep(100);
	}
	i = 0;
	while (++i <= info->num_of_phil)
		pthread_join(info->thread, NULL);
}

t_info	*init_info(int argc, char *argv[])
{
	t_info	*info;

	info = safe_malloc(sizeof(t_info));
	info->mutex = safe_malloc(sizeof(pthread_mutex_t));
	if (pthread_mutex_init(info->mutex, NULL) == -1)
		error("Mutex initialization error");
	info->fork = ft_calloc(info->num_of_phil + 1, sizeof(int));
	info->num_of_phil = ft_atoi(argv[1]);
	info->time_to_die = ft_atoi(argv[2]);
	info->time_to_eat = ft_atoi(argv[3]);
	info->time_to_sleep = ft_atoi(argv[4]);
	if (argc == 6)
		info->min_eat = ft_atoi(argv[5]);
	else
		info->min_eat = -1;
	return (info);
}

int	main(int argc, char *argv[])
{
	t_info	*info;

	if (argc < 5 || argc > 6)
		error("Invalid argument");
	info = init_info(argc, argv);
	philosophers(info);
	return (0);
}
