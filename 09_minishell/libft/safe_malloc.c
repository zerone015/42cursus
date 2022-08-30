/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   safe_malloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoson <yoson@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 14:43:30 by yoson             #+#    #+#             */
/*   Updated: 2022/08/30 14:46:44 by yoson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>

void    *safe_malloc(size_t size)
{
    void    *p;
    
    p = malloc(size);
    if (!p)
    {
        printf("%s \n", strerror(errno));
        exit(1);
    }
    return (p);
}
