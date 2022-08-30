/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoson <yoson@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 14:01:50 by yoson             #+#    #+#             */
/*   Updated: 2022/08/30 16:34:48 by yoson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

t_lst	*ft_lstnew(void *content)
{
	t_lst	*new;

	new = safe_malloc(sizeof(t_lst));
	new->content = content;
	new->next = NULL;
	return (new);
}
