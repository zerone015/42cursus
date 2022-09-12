/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoson <yoson@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 21:01:12 by yoson             #+#    #+#             */
/*   Updated: 2022/09/13 00:07:49 by yoson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <sys/time.h>
#include "philo_bonus.h"

static void	init_philo(t_info *info)
{
	int	i;

	i = -1;
	while (++i < info->num_of_philo)
	{
		info->philo[i].id = i + 1;
		info->philo[i].eat_cnt = 0;
		info->philo[i].last_time = 0;
		info->philo[i].dead_time = 0;
		info->philo[i].dead = 0;
		info->philo[i].info = info;
	}
}

static int	open_sem(t_info *info)
{
	info->fork = sem_open("fork", O_CREAT, S_IRWXU, info->num_of_philo);
	info->print = sem_open("print", O_CREAT, S_IRWXU, 1);
	info->die = sem_open("die", O_CREAT, S_IRWXU, 1);
	info->all_eat = sem_open("aeat", O_CREAT, S_IRWXU, info->num_of_philo + 1);
	if (info->fork == SEM_FAILED || info->print == SEM_FAILED || \
		info->die == SEM_FAILED || info->all_eat == SEM_FAILED)
		return (-1);
	return (0);
}

void	unlink_sem(void)
{
	sem_unlink("fork");
	sem_unlink("print");
	sem_unlink("die");
	sem_unlink("aeat");
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
	info->shared_var = 0;
	info->shared_flag = 1;
	info->philo = safe_malloc(sizeof(t_philo) * info->num_of_philo);
	init_philo(info);
	info->pid = ft_calloc(info->num_of_philo, sizeof(pid_t));
	if (open_sem(info) == -1)
		error("sem_open() failed");
	gettimeofday(&start, NULL);
	info->start_time = start.tv_sec * 1000 + start.tv_usec / 1000;
}
