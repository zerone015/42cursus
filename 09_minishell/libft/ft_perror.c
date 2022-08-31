/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_perror.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kijsong <kijsong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 14:35:35 by kijsong           #+#    #+#             */
/*   Updated: 2022/08/31 14:38:39 by kijsong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <stdlib.h>

void	ft_perror(const char *s)
{
	if (s)
		printf("%s: ", s);
	printf("%s\n", strerror(errno));
	exit(1);
}
