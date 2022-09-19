/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoson <yoson@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 20:31:34 by yoson             #+#    #+#             */
/*   Updated: 2022/09/19 21:51:21 by yoson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include "libft.h"

void	error(char *err_msg)
{
	ft_putendl_fd("Error", 2);
	if (err_msg)
		ft_putendl_fd(err_msg, 2);
	else
		perror(NULL);
	exit(1);
}
