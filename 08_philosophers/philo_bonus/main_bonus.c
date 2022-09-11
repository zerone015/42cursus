/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoson <yoson@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 23:44:46 by yoson             #+#    #+#             */
/*   Updated: 2022/09/11 21:59:49 by yoson            ###   ########.fr       */
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

void	monitor(t_info *info)
{
	int	temp;

	temp = info->shared_var;
	while (1)
	{
		if (waitpid(-1, NULL, WNOHANG) > 0 || info->shared_var == temp)
		{
			if (waitpid(-1, NULL, WNOHANG) <= 0 && info->shared_var == temp)
			{
				usleep(100);
				if (info->shared_var != temp)
					continue ;
			}
			philo_kill(info);
			info->shared_flag = 0;
			break ;
		}
	}
}

void	avoid_orphan(t_info *info, int count)
{
	int	i;

	i = -1;
	while (++i < count)
		waitpid(info->pid[i], NULL, 0);
	philo_kill(info);
	error("Thread create failed");
}

void	outsider(t_info *info)
{
	printf("%zu 1 has taken a fork\n", timestamp_in_ms(info->start_time));
	smart_sleep(info->time_to_die);
	printf("%zu 1 died\n", timestamp_in_ms(info->start_time));
	exit(0);
}

void	monitor_all_eat(t_info *info)
{
	while (info->shared_flag)
	{
		sem_wait(info->all_eat);
		info->shared_var++;
		sem_post(info->all_eat);
	}
}

void	philosophers(t_info *info)
{
	pthread_t	tid;
	int			i;

	if (info->num_of_philo == 1)
		outsider(info);
	info->pid[0] = 1;
	i = -1;
	while (++i < info->num_of_philo)
	{
		info->pid[i] = fork();
		if (info->pid[i] == -1)
			avoid_orphan(info, i);
		if (info->pid[i] == 0)
			action(&info->philo[i]);
	}
	if (pthread_create(&tid, NULL, (void *)monitor_all_eat, info) != 0)
		avoid_orphan(info, i);
	pthread_detach(tid);
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
