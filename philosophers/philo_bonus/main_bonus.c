/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoson <yoson@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 23:44:46 by yoson             #+#    #+#             */
/*   Updated: 2022/11/11 15:02:54 by yoson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "philo_bonus.h"

void	outsider(t_info *info)
{
	printf("%zu 1 has taken a fork\n", timestamp_in_ms(info->start_time));
	smart_sleep(info->time_to_die);
	printf("%zu 1 died\n", timestamp_in_ms(info->start_time));
	exit(0);
}

void	create_outsider(t_info *info)
{
	pid_t	pid;

	pid = fork();
	if (pid == -1)
		return ;
	if (pid == 0)
		outsider(info);
	waitpid(pid, NULL, 0);
}

void	philosophers(t_info *info, t_monitor *mon)
{
	int			i;

	if (info->num_of_philo == 1)
	{
		create_outsider(info);
		return ;
	}
	i = -1;
	while (++i < info->num_of_philo)
	{
		mon->pid[i] = fork();
		if (mon->pid[i] == -1)
		{
			philo_kill(mon);
			error("fork() failed");
		}
		if (mon->pid[i] == 0)
			action(&mon->philo[i]);
	}
	monitor(mon, info->must_eat);
}

int	main(int argc, char *argv[])
{
	t_info		info;
	t_monitor	monitor;

	if (argc < 5 || argc > 6)
		error("Invalid arguments");
	init_struct(&info, &monitor, argv);
	philosophers(&info, &monitor);
	return (0);
}
