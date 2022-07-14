/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoson <yoson@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 01:07:10 by yoson             #+#    #+#             */
/*   Updated: 2022/07/14 20:39:46 by yoson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>

char	*get_next_line(int fd);
size_t	gnl_strlen(const char *str);
char	*gnl_strdup(const char *src);
void	gnl_strlcpy(char *dest, const char *src, size_t len);

#endif
