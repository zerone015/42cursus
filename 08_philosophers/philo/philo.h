/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kijsong <kijsong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 16:14:33 by yoson             #+#    #+#             */
/*   Updated: 2022/09/10 22:36:47 by kijsong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

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
	int				time_to_die;
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
	pthread_mutex_t	die;
}	t_info;

int		ft_atoi(const char *str);
void	*safe_malloc(size_t size);
void	*ft_calloc(size_t count, size_t size);

void	*ft_memset(void *mem, int c, size_t len);
size_t	ft_strlen(const char *str);
void	ft_putstr_fd(char *s, int fd);
void	ft_putendl_fd(char *s, int fd);
void	*print_err(char *err_msg);

size_t	timestamp_in_ms(size_t start_time);
void	msleep(size_t time);

int		init_info(t_info *info, char *argv[]);
void	action(t_philo *philo);

#endif
