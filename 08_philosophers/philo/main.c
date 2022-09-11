/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoson <yoson@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 23:44:46 by yoson             #+#    #+#             */
/*   Updated: 2022/09/11 14:23:17 by yoson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "philo.h"

void	monitor(t_info *info)
{
	int	i;

	while (info->dead < 1 && info->must_eat)
	{
		i = -1;
		while (++i < info->num_of_philo)
		{
			if (info->philo[i].eat_cnt < info->must_eat)
				break ;
		}
		if (i == info->num_of_philo)
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
		smart_sleep(info->time_to_die);
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
