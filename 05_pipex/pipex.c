/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoson <yoson@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 19:36:53 by yoson             #+#    #+#             */
/*   Updated: 2022/07/28 21:52:01 by yoson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char *argv[], char *envp[])
{
	t_info	info;

	if (argc < 5 || parse_envp(&info, envp) || parse_argv(&info, argv))
		return (0);
	return (0);
}
