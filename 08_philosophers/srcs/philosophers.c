/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoson <yoson@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 16:10:18 by yoson             #+#    #+#             */
/*   Updated: 2022/09/09 16:09:43 by yoson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h> //gettimeofday
#include <sys/time.h> //gettimeofdady
#include <stdio.h> //test
#include <stdlib.h> //exit
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

size_t    timestamp_in_ms(size_t start_time)
{
    struct timeval	now;
	size_t			now_time;

    gettimeofday(&now, NULL);
	now_time = now.tv_sec * 1000 + now.tv_usec / 1000;
    return (now_time - start_time);
}

void	die(t_info *info, int id, size_t last_eat, size_t time_to_act)
{
	size_t			before_act;

	before_act = timestamp_in_ms(info->start_time);
	if (before_act - last_eat + time_to_act >= info->time_to_die)
	{
		printf("%zu %d died\n", last_eat + info->time_to_die, id);
		exit(0);
	}
	usleep(time_to_act * 1000);
}

void	action(t_info *info)
{
	int				id;
	int				cnt_eat;
	size_t			last_eat;

	id = info->id;
	cnt_eat = 0;
	last_eat = timestamp_in_ms(info->start_time);
	while (42)
	{
		// pthread_mutex_lock(info->mutex);
		while (info->fork[id] || info->fork[id % info->num_of_phil + 1])
			;
		info->fork[id] = 1;
		info->fork[id % info->num_of_phil + 1] = 1;
		printf("%zu %d has taken a fork\n", timestamp_in_ms(info->start_time), id);
		printf("%zu %d is eating\n", timestamp_in_ms(info->start_time), id);
		die(info, id, last_eat, info->time_to_eat);
		last_eat = timestamp_in_ms(info->start_time);
		info->fork[id] = 0;
		info->fork[id % info->num_of_phil + 1] = 0;
		// pthread_mutex_unlock(info->mutex);
		printf("%zu %d is sleeping\n", timestamp_in_ms(info->start_time), id);
		die(info, id, last_eat, info->time_to_sleep);
		printf("%zu %d is thinking\n", timestamp_in_ms(info->start_time), id);
		cnt_eat++;
	}
}

void	philosophers(t_info *info)
{
	struct timeval	start;
	int				i;

	gettimeofday(&start, NULL);
	info->start_time = start.tv_sec * 1000 + start.tv_usec / 1000;
	i = 1;
	while (i <= info->num_of_phil)
	{
		info->id = i;
		pthread_create(&info->thread, NULL, (void *)action, info);
		usleep(100);
		i += 2;
	}
	usleep(info->time_to_eat * 1000);
	i = 2;
	while (i <= info->num_of_phil)
	{
		info->id = i;
		pthread_create(&info->thread, NULL, (void *)action, info);
		usleep(100);
		i += 2;
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
