/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoson <yoson@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 16:45:48 by yoson             #+#    #+#             */
/*   Updated: 2022/10/25 04:13:21 by yoson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <limits.h>

void	init_array(t_info *info)
{
	unsigned int	i;

	i = 0;
	while (i < sizeof(info->flag) / sizeof(intptr_t))
		info->flag[i++] = NULL;
	info->flag['0'] = &info->zero;
	info->flag[' '] = &info->space;
	info->flag['+'] = &info->plus;
	info->flag['-'] = &info->minus;
	info->flag['#'] = &info->sharp;
	i = 0;
	while (i < sizeof(info->type) / sizeof(intptr_t))
		info->type[i++] = NULL;
	info->type['c'] = print_char;
	info->type['s'] = print_str;
	info->type['p'] = print_address;
	info->type['d'] = print_decimal;
	info->type['i'] = print_decimal;
	info->type['u'] = print_u_decimal;
	info->type['x'] = print_hex_lower;
	info->type['X'] = print_hex_upper;
	info->type['%'] = print_percent;
}

void	init_info(t_info *info)
{
	info->width = 0;
	info->zero = DISABLE;
	info->space = DISABLE;
	info->plus = DISABLE;
	info->sharp = DISABLE;
	info->minus = DISABLE;
	info->dot = DISABLE;
	info->precision = 0;
}
