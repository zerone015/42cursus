/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoson <yoson@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 16:14:33 by yoson             #+#    #+#             */
/*   Updated: 2022/11/11 15:01:45 by yoson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_BONUS_H
# define PHILO_BONUS_H

# include <unistd.h>
# include <semaphore.h>

typedef struct s_philo
{
	int				id;
	int				eat_cnt;
	time_t			last_time;
	struct s_info	*info;
}	t_philo;

typedef struct s_info
{
	int		num_of_philo;
	time_t	time_to_die;
	time_t	time_to_eat;
	time_t	time_to_sleep;
	int		must_eat;
	time_t	start_time;
	sem_t	*fork;
	sem_t	*print;
	sem_t	*all_eat;
}	t_info;

typedef struct s_monitor
{
	int		num_of_philo;
	pid_t	*pid;
	t_philo	*philo;
	sem_t	*all_eat;
	sem_t	*monitor_sem;
	int		is_exit;
}	t_monitor;

int		ft_atoi(const char *str);
void	error(char *err_msg);
void	*safe_malloc(size_t size);
void	*ft_calloc(size_t count, size_t size);

void	*ft_memset(void *mem, int c, size_t len);
size_t	ft_strlen(const char *str);
void	ft_putstr_fd(char *s, int fd);
void	ft_putendl_fd(char *s, int fd);

time_t	timestamp_in_ms(time_t start_time);
void	smart_sleep(time_t time);

void	init_struct(t_info *info, t_monitor *monitor, char *argv[]);
void	monitor(t_monitor *mon, int must_eat);
void	philo_kill(t_monitor *monitor);
void	action(t_philo *philo);

#endif
