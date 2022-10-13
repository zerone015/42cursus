/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoson <yoson@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 19:06:04 by yoson             #+#    #+#             */
/*   Updated: 2022/10/14 04:58:40 by yoson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# else
#  if BUFFER_SIZE < 1
#   error INVALID BUFFER_SIZE
#  endif
# endif

typedef struct s_node
{
	int				fd;
	char			*backup;
	struct s_node	*next;
}	t_node;

typedef struct s_list
{
	t_node	*tail;
	t_node	*cur;
	t_node	*before;
	int		num_of_fd;
}	t_list;

char	*get_next_line(int fd);
char	*remove_fd(t_list *list);
size_t	ft_strlen(const char *str);
char	*ft_strchr(const char *str, int c);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_substr(char const *src, unsigned int start, size_t len);

#endif
