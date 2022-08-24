/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoson <yoson@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 14:01:50 by yoson             #+#    #+#             */
/*   Updated: 2022/08/24 18:04:39 by yoson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

t_lst	*ft_lstnew(void *content)
{
	t_lst	*new;

	new = (t_lst *) malloc(sizeof(t_lst));
	if (!new)
		return (NULL);
	new->content = content;
	new->next = NULL;
	return (new);
}
