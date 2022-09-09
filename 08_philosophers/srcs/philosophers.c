/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoson <yoson@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 16:10:18 by yoson             #+#    #+#             */
/*   Updated: 2022/09/09 21:51:02 by yoson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h> //gettimeofday
#include <sys/time.h>
#include <stdio.h> //test
#include <stdlib.h> //exit
#include "philosophers.h"

size_t	timestamp_in_ms(size_t start_time)
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

void	action(void *void_philo)
{
	t_philo	*philo;
	t_info	*info;
	int		id;

	philo = void_philo;
	id = philo->id;
	info = philo->info;
	if (id % 2)
		usleep(15000);
	while (42)
	{
		pthread_mutex_lock(&info->fork[philo->left_fork]);
		printf("%zu %d has taken a fork\n", timestamp_in_ms(info->start_time), id);
		pthread_mutex_lock(&info->fork[philo->right_fork]);
		printf("%zu %d has taken a fork\n", timestamp_in_ms(info->start_time), id);
		pthread_mutex_lock(&info->print);
		printf("%zu %d eat\n", timestamp_in_ms(info->start_time), id);
		pthread_mutex_unlock(&info->print);
		usleep(info->time_to_eat * 1000);
		pthread_mutex_unlock(&info->fork[philo->left_fork]);
		pthread_mutex_unlock(&info->fork[philo->right_fork]);
		printf("%zu %d sleep\n", timestamp_in_ms(info->start_time), id);
		usleep(info->time_to_sleep * 1000);
	}
}

void	philosophers(t_info *info)
{
	t_philo	*philo;
	int		i;

	i = 0;
	while (++i <= info->num_of_phil)
	{
		philo = &info->philo[i];
		pthread_create(&philo->tid, NULL, (void *)action, philo);
	}
	i = 0;
	while (1)
		;
}

int	main(int argc, char *argv[])
{
	t_info	*info;

	if (argc < 5 || argc > 6)
		error("Invalid argument");
	info = init_info(argv);
	philosophers(info);
	return (0);
}
