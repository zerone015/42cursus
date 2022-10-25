/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoson <yoson@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 16:45:48 by yoson             #+#    #+#             */
/*   Updated: 2022/10/25 21:48:54 by yoson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <limits.h>

void	init_array(int (*types[])(va_list))
{
	unsigned int	i;

	i = 0;
	while (i < 255)
		types[i++] = NULL;
	types['c'] = print_char;
	types['s'] = print_str;
	types['p'] = print_address;
	types['d'] = print_decimal;
	types['i'] = print_decimal;
	types['u'] = print_u_decimal;
	types['x'] = print_hex_lower;
	types['X'] = print_hex_upper;
	types['%'] = print_percent;
}
