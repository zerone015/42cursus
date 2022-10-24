/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoson <yoson@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 16:45:48 by yoson             #+#    #+#             */
/*   Updated: 2022/10/24 21:13:47 by yoson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <limits.h>

void	init_array(t_info *info)
{
	unsigned int	i;

	i = 0;
	while (i < sizeof(info->flag_addr) / sizeof(intptr_t))
		info->flag_addr[i++] = NULL;
	info->flag_addr['0'] = &info->zero;
	info->flag_addr[' '] = &info->space;
	info->flag_addr['+'] = &info->plus;
	info->flag_addr['-'] = &info->minus;
	info->flag_addr['#'] = &info->sharp;
	i = 0;
	while (i < sizeof(info->functions) / sizeof(intptr_t))
		info->functions[i++] = NULL;
	info->functions['c'] = print_char;
	info->functions['s'] = print_str;
	info->functions['p'] = print_hex_address;
	info->functions['d'] = print_nbr;
	info->functions['i'] = print_nbr;
	info->functions['u'] = print_unbr;
	info->functions['x'] = print_hex_lower;
	info->functions['X'] = print_hex_upper;
	info->functions['%'] = print_percent;
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
