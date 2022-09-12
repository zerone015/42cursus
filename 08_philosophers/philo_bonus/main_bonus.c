/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoson <yoson@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 23:44:46 by yoson             #+#    #+#             */
/*   Updated: 2022/09/13 01:20:47 by yoson            ###   ########.fr       */
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

void	philosophers(t_info *info)
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
