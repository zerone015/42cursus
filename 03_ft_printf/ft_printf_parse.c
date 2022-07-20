/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_parse.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoson <yoson@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 20:29:48 by yoson             #+#    #+#             */
/*   Updated: 2022/07/20 22:35:46 by yoson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	is_flag(char c)
{
	if (c == ' ' || c == '+' || c == '#' || c == '-')
		return (1);
	return (0);
}

void	parse_flag(t_info *info, const char **format)
{
	while (is_flag(**format))
	{
		if (**format == ' ')
			info->space = 1;
		else if (**format == '+')
			info->plus = 1;
		else if (**format == '-')
			info->minus = 1;
		else if (**format == '#')
			info->sharp = 1;
		(*format)++;
	}
}

void	parse_width(t_info *info, const char **format)
{
	if (**format == '0')
	{
		info->zero = 1;
		while (**format != '0')
			(*format)++;
	}
	while (ft_isdigit(**format))
	{
		info->width *= 10;
		info->width += **format - '0';
		(*format)++;
	}
}

void	parse_precision(t_info *info, const char **format)
{
	if (**format != '.')
		return ;
	while (ft_isdigit(**format))
	{
		info->precision *= 10;
		info->precision += **format - '0';
		(*format)++;
	}
}
