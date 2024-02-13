/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksansom <ksansom@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 11:03:10 by ksansom           #+#    #+#             */
/*   Updated: 2024/02/13 16:16:54 by ksansom          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <string.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/types.h>
# include <signal.h>
# include <pthread.h> 
# include <sys/time.h>
# include <sys/wait.h>
# include <fcntl.h>
# include <sys/stat.h>
# include <semaphore.h>

typedef enum e_state
{
	EATING,
	SLEEPING,
	THINKING,
	DEAD,
	FULL,
	IDLE
}	t_state;

typedef struct s_data
{
	int				num_philos;
	int				num_meals;
	int				loop;
	int				time_start;
	int				time_eat;
	int				time_sleep;
	int				time_die;
	pthread_mutex_t	mut_eat;
	pthread_mutex_t	mut_sleep;
	pthread_mutex_t	mut_print;
	pthread_mutex_t	mut_num_philos;
}	t_data;

/*INITIALIZATION*/
void	init_data(t_data *data, char **av);

/*UTILS*/
int		ft_atoi(char *str);

#endif