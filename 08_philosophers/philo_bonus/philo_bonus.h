/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoson <yoson@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 16:14:33 by yoson             #+#    #+#             */
/*   Updated: 2022/09/13 12:16:30 by yoson            ###   ########.fr       */
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
	int				dead;
	time_t			dead_time;
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
	t_philo	*philo;
	pid_t	*pid;
	sem_t	*fork;
	sem_t	*print;
	sem_t	*all_eat;
	sem_t	*kill;
	int		monitor_switch;
	int		already_killed;
}	t_info;

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

void	init_info(t_info *info, char *argv[]);
void	monitor(t_info *info);
void	avoid_orphan_kill(t_info *info, int size, char *msg);
void	philo_kill(t_info *info, pid_t dead);
void	action(t_philo *philo);

#endif
