/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoson <yoson@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 16:14:33 by yoson             #+#    #+#             */
/*   Updated: 2022/09/13 02:58:29 by yoson            ###   ########.fr       */
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
	time_t			last_time;
	pthread_t		tid;
	struct s_info	*info;
}	t_philo;

typedef struct s_info
{
	int				num_of_philo;
	time_t			time_to_die;
	time_t			time_to_eat;
	time_t			time_to_sleep;
	int				must_eat;
	int				all_eat;
	int				dead;
	int				dead_philo;
	time_t			dead_time;
	time_t			start_time;
	t_philo			*philo;
	pthread_mutex_t	*fork;
	pthread_mutex_t	print;
	pthread_mutex_t	dead_mutex;
}	t_info;

int		ft_atoi(const char *str);
void	*safe_malloc(size_t size);

void	*ft_memset(void *mem, int c, size_t len);
size_t	ft_strlen(const char *str);
void	ft_putstr_fd(char *s, int fd);
void	ft_putendl_fd(char *s, int fd);
void	*print_err(char *err_msg);

time_t	timestamp_in_ms(time_t start_time);
void	smart_sleep(time_t time);

int		init_info(t_info *info, char *argv[]);
void	action(t_philo *philo);

#endif
