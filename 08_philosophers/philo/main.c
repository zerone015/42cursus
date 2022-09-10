/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoson <yoson@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 23:44:46 by yoson             #+#    #+#             */
/*   Updated: 2022/09/10 22:04:37 by yoson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h> //gettimeofday
#include <sys/time.h>
#include <stdlib.h>
#include "philo.h"

void	ft_usleep(size_t time)
{
	struct timeval	now;
	size_t			start;

	start = timestamp_in_ms(time);
	while (get_time() < start + time)
		usleep(10);
}

size_t	timestamp_in_ms(size_t start_time)
{
	struct timeval	now;
	size_t			now_time;

	gettimeofday(&now, NULL);
	now_time = now.tv_sec * 1000 + now.tv_usec / 1000;
	return (now_time - start_time);
}

void	ft_usleep(t_info *info, t_philo *philo, size_t time_to_act)
{
	size_t			before_act;

	before_act = timestamp_in_ms(info->start_time);
	pthread_mutex_lock(&info->die);
	if (before_act - philo->last_time + time_to_act > info->time_to_die && !info->dead)
	{
		info->dead = 1;
		info->dead_philo = philo->id;
		info->dead_time = philo->last_time + info->time_to_die;
	}
	pthread_mutex_unlock(&info->die);
	usleep(time_to_act * 1000);
}

int	dead_check(t_info *info, t_philo *philo, char *msg)
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

int	eating(t_philo *philo)
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

int	sleeping(t_philo *philo)
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
		usleep(15000);
	while (!info->all_eat)
	{
		if (eating(philo) || sleeping(philo))
			return ;
		if (dead_check(info, philo, "%zu %d is thinking\n"))
			return ;
	}
}

void	monitor(t_info *info)
{
	int	i;
	int	flag;

	while (info->dead < 1 && info->must_eat)
	{
		flag = 1;
		i = -1;
		while (++i < info->num_of_philo)
		{
			if (info->philo[i].eat_cnt < info->must_eat)
				flag = 0;
		}
		if (flag)
		{
			info->all_eat = 1;
			break ;
		}
	}
}

void	philosophers(t_info *info)
{
	t_philo	*philo;
	int		i;

	if (info->num_of_philo == 1)
	{
		printf("%zu 1 has taken a fork\n", timestamp_in_ms(info->start_time));
		usleep(info->time_to_die * 1000);
		printf("%zu 1 died\n", timestamp_in_ms(info->start_time));
		return ;
	}
	i = -1;
	while (++i < info->num_of_philo)
	{
		philo = &info->philo[i];
		if (pthread_create(&philo->tid, NULL, (void *)action, philo) != 0)
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
	{
		print_err("Invalid arguments");
		return (1);
	}
	if (init_info(&info, argv) == -1)
		return (1);
	philosophers(&info);
	return (0);
}
