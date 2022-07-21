/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoson <yoson@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 01:00:42 by yoson             #+#    #+#             */
/*   Updated: 2022/07/21 17:18:07 by yoson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"
#include <unistd.h>

int	ft_isdigit(char c)
{
	if (c >= '0' && c <= '9')
		return (TRUE);
	else
		return (FALSE);
}

int	is_flag(char c)
{
	if (c == ' ' || c == '+' || c == '#' || c == '-' || c == '0')
		return (TRUE);
	return (FALSE);
}

int	get_max(int a, int b)
{
	if (a > b)
		return (a);
	else
		return (b);
}

size_t	ft_strlen(const char *str)
{
	size_t	len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

int	putnchar(char c, int n)
{
	int	print_len;

	print_len = 0;
	while (n-- > 0)
		print_len += write(1, &c, 1);
	return (print_len);
}
