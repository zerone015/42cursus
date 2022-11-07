/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoson <yoson@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 16:45:48 by yoson             #+#    #+#             */
/*   Updated: 2022/11/07 11:53:50 by yoson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include "ft_printf_bonus.h"

void	init_parse_table(t_info *info)
{
	unsigned int	i;

	i = 0;
	while (i < sizeof(info->flags) / sizeof(intptr_t))
		info->flags[i++] = NULL;
	info->flags['0'] = &info->zero;
	info->flags[' '] = &info->space;
	info->flags['+'] = &info->plus;
	info->flags['-'] = &info->minus;
	info->flags['#'] = &info->sharp;
	i = 0;
	while (i < sizeof(info->types) / sizeof(intptr_t))
		info->types[i++] = NULL;
	info->types['c'] = print_char;
	info->types['s'] = print_str;
	info->types['p'] = print_address;
	info->types['d'] = print_decimal;
	info->types['i'] = print_decimal;
	info->types['u'] = print_u_decimal;
	info->types['x'] = print_hex_lower;
	info->types['X'] = print_hex_upper;
	info->types['%'] = print_percent;
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
