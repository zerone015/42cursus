/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoson <yoson@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 16:14:33 by yoson             #+#    #+#             */
/*   Updated: 2022/09/10 14:52:17 by yoson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <stddef.h>
# include <pthread.h>

typedef struct s_philo
{
	int				id;
	int				eat_cnt;
	int				left_fork;
	int				right_fork;
	size_t			last_time;
	pthread_t		tid;
	struct s_info	*info;
}	t_philo;

typedef struct s_info
{
	int				num_of_philo;
	size_t			time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				must_eat;
	int				all_eat;
	int				dead;
	int				dead_philo;
	size_t			dead_time;
	size_t			start_time;
	t_philo			*philo;
	pthread_mutex_t	*fork;
	pthread_mutex_t	print;
}	t_info;

int		ft_atoi(const char *str);
void	*safe_malloc(size_t size);
void	*ft_calloc(size_t count, size_t size);

void	*ft_memset(void *mem, int c, size_t len);
size_t	ft_strlen(const char *str);
void	ft_putstr_fd(char *s, int fd);
void	ft_putendl_fd(char *s, int fd);
void	error(char *err_msg);

size_t	timestamp_in_ms(size_t start_time);
void	init_info(t_info *info, char *argv[]);

#endif
