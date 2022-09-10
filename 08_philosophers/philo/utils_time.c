/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_time.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kijsong <kijsong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 22:28:44 by kijsong           #+#    #+#             */
/*   Updated: 2022/09/10 22:29:53 by kijsong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <sys/time.h>

size_t	timestamp_in_ms(size_t start_time)
{
	struct timeval	now;

	gettimeofday(&now, NULL);
	return (now.tv_sec * 1000 + now.tv_usec / 1000 - start_time);
}

void	msleep(size_t time)
{
	size_t	start;

	start = timestamp_in_ms(0);
	while (timestamp_in_ms(0) < start + time)
		usleep(10);
}
