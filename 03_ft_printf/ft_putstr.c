/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoson <yoson@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 19:06:59 by yoson             #+#    #+#             */
/*   Updated: 2022/07/20 03:29:21 by yoson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <unistd.h>
#include <limits.h>

int	ft_putstr(char *str)
{
	if (!str)
		return (write(1, "(null)", 6));
	if (ft_strlen(str) >= INT_MAX)
		return (-1);
	return (write(1, str, ft_strlen(str)));
}
