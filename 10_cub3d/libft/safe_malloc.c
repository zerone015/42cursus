/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   safe_malloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoson <yoson@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 14:24:55 by kijsong           #+#    #+#             */
/*   Updated: 2022/09/19 20:31:16 by yoson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void	*safe_malloc(size_t size)
{
	void	*p;

	p = malloc(size);
	if (!p)
		error("out of memory");
	return (p);
}
