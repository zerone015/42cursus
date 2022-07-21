/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoson <yoson@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 16:45:48 by yoson             #+#    #+#             */
/*   Updated: 2022/07/21 17:15:51 by yoson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	struct_init(t_info *info)
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
