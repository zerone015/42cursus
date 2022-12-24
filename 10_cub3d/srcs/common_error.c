/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   common_error.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoson <yoson@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 14:54:09 by yoson             #+#    #+#             */
/*   Updated: 2022/12/23 18:16:14 by yoson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <stdlib.h>
#include "cub3d.h"

static void print_common_msg(void)
{
    printf("%s%s", "Error\n", "cub3D: ");
}

void    ft_error(const char *arg, const char *error_msg)
{
    print_common_msg();
    printf("%s: %s \n", arg, error_msg);
    exit(EXIT_FAILURE);
}

void    ft_perror(const char *arg)
{
    print_common_msg();
    if (arg)
        printf("%s: ", arg);
    perror(NULL);
    exit(EXIT_FAILURE);
}

void    ft_strerror(const char *arg)
{
    const char  *error_msg;

    print_common_msg();
    if (arg)
        printf("%s: ", arg);
    error_msg = strerror(errno);
    printf("%s \n", error_msg);
    exit(EXIT_FAILURE);
}