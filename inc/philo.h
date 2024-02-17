/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksansom <ksansom@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 11:03:10 by ksansom           #+#    #+#             */
/*   Updated: 2024/02/16 13:49:27 by ksansom          ###   ########.fr       */
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

typedef struct s_philosopher
{
	int				id;
	int				meals_eaten;
	struct s_data	*data;
	t_state			state;
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*right_fork;
	pthread_mutex_t	mut_state;
	pthread_mutex_t	mut_meals_eaten;
	pthread_mutex_t	mut_last_meal_time;
	unsigned long	last_meal_time;				
}	t_philosopher;

typedef struct s_data
{
	int				num_philos;
	int				num_meals;
	int				keep_loop;
	unsigned long	time_start;
	unsigned long	time_eat;
	unsigned long	time_sleep;
	unsigned long	time_die;
	pthread_mutex_t	mut_time_eat;
	pthread_mutex_t	mut_time_sleep;
	pthread_mutex_t	mut_time_die;
	pthread_mutex_t	mut_print;
	pthread_mutex_t	mut_num_philos;
	pthread_mutex_t	mut_time_start;
	pthread_mutex_t	mut_keep_loop;
	pthread_t		check_all_alive;
	pthread_t		check_all_full;
	t_philosopher	*philosophers;
	pthread_mutex_t	*forks;
	pthread_t		*philo_threads;
}	t_data;

/*INITIALIZATION*/
int				init_data(t_data *data, char **av);
int				init_malloc_data(t_data *data);
int				init_philosophers(t_data *data);

/*UTILS*/
int				ft_atoi(char *str);
int				ft_exit(t_data *data, char *str, int ret_code);
int				ft_strlen(char *str);
void			free_phil_data(t_data *data);

/*UTILS_TIME*/
unsigned long	ft_get_time(void);
void			ft_update_meal_time(t_philosopher *philo);

/*UTILS_GET*/
int				get_num_philos(t_data *data);

/*EATING*/

/*UTILS_PRINT*/
int				ft_print_usage(void);
void			ft_check_validity(t_data *data);

#endif