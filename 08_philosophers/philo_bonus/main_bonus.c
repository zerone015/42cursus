/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoson <yoson@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 23:44:46 by yoson             #+#    #+#             */
/*   Updated: 2022/09/12 21:55:23 by yoson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <signal.h>
#include <stdlib.h>
#include "philo_bonus.h"

void	philo_kill(t_info *info)
{
	int	i;

	i = -1;
	while (++i < info->num_of_philo && info->pid[i] > 0)
		kill(info->pid[i], SIGTERM);
}

void	avoid_orphan_kill(t_info *info, int size, char *msg)
{
	int	i;

	i = -1;
	while (++i < size)
		waitpid(info->pid[i], NULL, 0);
	philo_kill(info);
	error(msg);
}

void	outsider(t_info *info)
{
	printf("%zu 1 has taken a fork\n", timestamp_in_ms(info->start_time));
	smart_sleep(info->time_to_die);
	printf("%zu 1 died\n", timestamp_in_ms(info->start_time));
	exit(0);
}

void	macro_all_eat(t_info *info)
{
	while (info->shared_flag)
	{
		sem_wait(info->all_eat);
		info->shared_var++;
		sem_post(info->all_eat);
	}
}

void	monitor_dead(t_info *info)
{
	while (1)
	{
		if (waitpid(-1, NULL, WNOHANG) > 0)
		{
			philo_kill(info);
			info->shared_flag = 0;
			break ;
		}
	}
}

void	monitor_all_eat(t_info *info)
{
	int	temp;

	while (1)
	{
		temp = info->shared_var;
		smart_sleep(40);
		if (info->shared_var == temp)
		{
			philo_kill(info);
			info->shared_flag = 0;
			break ;
		}
	}
}

void	monitor(t_info *info)
{
	pthread_t	tid;

	if (pthread_create(&tid, NULL, (void *)macro_all_eat, info) != 0)
		avoid_orphan_kill(info, info->num_of_philo, "Thread create failed");
	pthread_detach(tid);
	if (pthread_create(&tid, NULL, (void *)monitor_all_eat, info) != 0)
		avoid_orphan_kill(info, info->num_of_philo, "Thread create failed");
	pthread_detach(tid);
	monitor_dead(info);
}

void	philosophers(t_info *info)
{
	int			i;

	if (info->num_of_philo == 1)
		outsider(info);
	i = -1;
	while (++i < info->num_of_philo)
	{
		info->pid[i] = fork();
		if (info->pid[i] == -1)
			avoid_orphan_kill(info, i, "fork() failed");
		if (info->pid[i] == 0)
			action(&info->philo[i]);
	}
	monitor(info);
}

int	main(int argc, char *argv[])
{
	t_info	info;

	if (argc < 5 || argc > 6)
		error("Invalid arguments");
	init_info(&info, argv);
	philosophers(&info);
	unlink_sem();
	return (0);
}
