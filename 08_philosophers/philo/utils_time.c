/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_time.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoson <yoson@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 22:28:44 by kijsong           #+#    #+#             */
/*   Updated: 2022/09/13 17:50:11 by yoson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <sys/time.h>

time_t	timestamp_in_ms(time_t start_time)
{
	struct timeval	now;

	gettimeofday(&now, NULL);
	return (now.tv_sec * 1000 + now.tv_usec / 1000 - start_time);
}

void	smart_sleep(time_t time)
{
	time_t	start;

	start = timestamp_in_ms(0);
	while (timestamp_in_ms(0) < start + time)
		usleep(100);
}
