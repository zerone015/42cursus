/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoson <yoson@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 23:44:46 by yoson             #+#    #+#             */
/*   Updated: 2022/09/10 14:54:52 by yoson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h> //gettimeofday
#include <sys/time.h>
#include <stdio.h> //test
#include <stdlib.h>
#include "philosophers.h"

size_t	timestamp_in_ms(size_t start_time)
{
	struct timeval	now;
	size_t			now_time;

	gettimeofday(&now, NULL);
	now_time = now.tv_sec * 1000 + now.tv_usec / 1000;
	return (now_time - start_time);
}

void	dead(t_info *info, t_philo *philo, size_t time_to_act)
{
	size_t			before_act;

	before_act = timestamp_in_ms(info->start_time);
	if (before_act - philo->last_time + time_to_act >= info->time_to_die)
	{
		info->dead = 1;
		info->dead_philo = philo->id;
		info->dead_time = philo->last_time + info->time_to_die;
		return ;
	}
	usleep(time_to_act * 1000);
}

int	dead_check(t_info *info, t_philo *philo, char *msg)
{
	size_t	timestamp;

	timestamp = timestamp_in_ms(info->start_time);
	if (timestamp > info->dead_time)
	{
		printf("%zu %d died\n", info->dead_time, philo->id);
		pthread_mutex_unlock(&info->fork[philo->left_fork]);
		pthread_mutex_unlock(&info->fork[philo->right_fork]);
		return (1);
	}
	printf(msg, timestamp, philo->id);
	return (0);
}

void	eating(t_philo *philo)
{
	t_info	*info;

	info = philo->info;
	pthread_mutex_lock(&info->fork[philo->left_fork]);
	printf("%zu %d has taken a fork\n", timestamp_in_ms(info->start_time), philo->id);
	pthread_mutex_lock(&info->fork[philo->right_fork]);
	printf("%zu %d has taken a fork\n", timestamp_in_ms(info->start_time), philo->id);
	// if (dead_check(info, philo, "%zu %d has taken a fork\n") == 1)
	// 	return ;
	// if (dead_check(info, philo, "%zu %d has taken a fork\n") == 1)
	// 	return ;
	pthread_mutex_lock(&info->print);
	printf("%zu %d is eating\n", timestamp_in_ms(info->start_time), philo->id);
	pthread_mutex_unlock(&info->print);
	usleep(info->time_to_eat * 1000);
	// dead(info, philo, info->time_to_eat);
	philo->last_time = timestamp_in_ms(info->start_time);
	(philo->eat_cnt)++;
	pthread_mutex_unlock(&info->fork[philo->left_fork]);
	pthread_mutex_unlock(&info->fork[philo->right_fork]);
}

void	sleeping(t_philo *philo)
{
	t_info	*info;

	info = philo->info;
	printf("%zu %d is sleeping\n", timestamp_in_ms(info->start_time), philo->id);
	usleep(info->time_to_sleep * 1000);
}

void	routine(t_philo *philo)
{
	t_info	*info;

	info = philo->info;
	if (philo->id % 2)
		usleep(15000);
	while (!info->dead)
	{
		if (info->all_eat)
			return ;
		eating(philo);
		sleeping(philo);
		printf("%zu %d is thinking\n", timestamp_in_ms(info->start_time), philo->id);
	}
}

void	monitor(t_info *info)
{
	int	i;

	while (info->must_eat)
	{
		i = -1;
		while (++i < info->num_of_philo && info->philo[i].eat_cnt >= info->must_eat)
			;
		if (i == info->num_of_philo)
		{
			info->all_eat = 1;
			break ;
		}
	}
	while (1)
	{
		if (info->dead)
			exit(0);
	}
	// {
	// 	i = -1;
	// 	while (!info->dead && ++i < info->num_of_philo)
	// 	{
	// 		pthread_mutex_lock(&info->print);
	// 		if (timestamp_in_ms(info->start_time) - info->philo[i].last_time < info->time_to_die)
	// 		{
	// 			info->dead = 1;
	// 			printf("%zu %d died\n", timestamp_in_ms(info->start_time), info->philo[i].id);
	// 		}
	// 		pthread_mutex_unlock(&info->print);
	// 		usleep(100);
	// 	}
	// }
}

void	philosophers(t_info *info)
{
	t_philo	*philo;
	int		i;

	i = -1;
	while (++i < info->num_of_philo)
	{
		philo = &info->philo[i];
		if (pthread_create(&philo->tid, NULL, (void *)routine, philo) != 0)
			return ;
	}
	monitor(info);
	i = -1;
	while (++i < info->num_of_philo)
		pthread_join(info->philo[i].tid, NULL);
}

int	main(int argc, char *argv[])
{
	t_info	info;

	if (argc < 5 || argc > 6)
		error("Invalid arguments");
	init_info(&info, argv);
	philosophers(&info);
	return (0);
}
