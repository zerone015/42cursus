/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_string.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoson <yoson@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 12:38:33 by yoson             #+#    #+#             */
/*   Updated: 2022/09/09 12:45:46 by yoson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "philosophers.h"

void	*ft_memset(void *mem, int c, size_t len)
{
	unsigned char	*p;

	p = (unsigned char *)mem;
	while (len--)
		*p++ = (unsigned char)c;
	return (mem);
}

size_t	ft_strlen(const char *str)
{
	size_t	len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

void	ft_putstr_fd(char *s, int fd)
{
	write(fd, s, ft_strlen(s));
}

void	ft_putendl_fd(char *s, int fd)
{
	write(fd, s, ft_strlen(s));
	write(fd, "\n", 1);
}

void	error(char *err_msg)
{
	ft_putstr_fd("Error: ", 2);
	ft_putendl_fd(err_msg, 2);
	exit(1);
}
