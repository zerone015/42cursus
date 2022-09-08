/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   safe_malloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kijsong <kijsong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 14:24:55 by kijsong           #+#    #+#             */
/*   Updated: 2022/08/31 14:45:13 by kijsong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void	*safe_malloc(size_t size)
{
	void	*p;

	p = malloc(size);
	if (!p)
		ft_perror(NULL);
	return (p);
}
