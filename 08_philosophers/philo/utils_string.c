/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_string.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kijsong <kijsong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 12:38:33 by yoson             #+#    #+#             */
/*   Updated: 2022/09/10 22:31:05 by kijsong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "philo.h"

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

void	*print_err(char *err_msg)
{
	ft_putstr_fd("print_err: ", 2);
	ft_putendl_fd(err_msg, 2);
	return (NULL);
}
