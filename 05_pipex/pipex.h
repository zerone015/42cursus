/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoson <yoson@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 18:58:31 by yoson             #+#    #+#             */
/*   Updated: 2022/07/28 22:09:16 by yoson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

typedef struct s_arg
{
	char	*infile;
	char	*outfile;
	char	**cmd;
	char	**path;
}	t_arg;

# define ERROR -1

int		parse_envp(t_info *info, char *envp[]);
int		parse_argv(t_info *info, char *argv[], int argc);

#endif
