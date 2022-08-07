/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoson <yoson@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/07 22:01:16 by yoson             #+#    #+#             */
/*   Updated: 2022/08/07 22:01:38 by yoson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <unistd.h>

int	print_error(char *content)
{
	ft_putendl_fd("error", STDERR_FILENO);
	ft_putendl_fd(content, STDERR_FILENO);
	return (FALSE);
}
