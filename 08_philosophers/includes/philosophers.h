/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoson <yoson@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 16:14:33 by yoson             #+#    #+#             */
/*   Updated: 2022/09/08 22:07:22 by yoson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include "../libft/libft.h"

enum e_state
{
	EATING,
	SLEEPING,
	THINKING
};

typedef struct s_info
{
	pthread_mutex_t	*mutex;
	t_philo			*philo;
	int				*fork;
	int				num_of_phil;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				min_eat;
}	t_info;

typedef struct s_philo
{
	int				id;
	int				state;
	pthread_t		thread;
}	t_philo;

#endif
