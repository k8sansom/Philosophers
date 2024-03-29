/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksansom <ksansom@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 11:03:10 by ksansom           #+#    #+#             */
/*   Updated: 2024/03/01 16:53:20 by ksansom          ###   ########.fr       */
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
	size_t			last_meal_time;				
}	t_philosopher;

typedef struct s_data
{
	int				num_philos;
	int				num_meals;
	int				keep_loop;
	size_t			time_start;
	size_t			time_eat;
	size_t			time_sleep;
	size_t			time_die;
	pthread_mutex_t	mut_print;
	pthread_mutex_t	mut_keep_loop;
	pthread_t		check_all_alive;
	pthread_t		check_all_full;
	t_philosopher	*philosophers;
	pthread_mutex_t	*forks;
	pthread_t		*philo_threads;
}	t_data;

/*INITIALIZATION*/
int		ft_input_check(int ac, char **av);
int		init_data(t_data *data, char **av);
int		init_malloc_data(t_data *data);
void	init_philosophers(t_data *data);
void	init_forks(t_data *data);

/*UTILS*/
int		ft_atoi(char *str);
int		ft_strlen(char *str);
void	ft_free(t_data *data);
int		ft_isdigit(int ac, char **av);

/*UTILS_TIME*/
size_t	ft_get_time(void);
void	ft_update_meal_time(t_philosopher *philo);
void	ft_usleep(size_t time_sleep);

/*UTILS_GET*/
t_state	get_philo_state(t_philosopher *philo);
int		get_keep_loop(t_data *data);
size_t	get_last_meal(t_philosopher *philo);
int		get_meals_eaten(t_philosopher *philo);

/*UTILS_SET*/
void	set_philo_state(t_philosopher *philo, t_state state);
void	set_keep_loop(t_data *data, int set_to);

/*EATING*/
int		ft_take_forks(t_philosopher *philo);
int		ft_eat(t_philosopher *philo);
int		ft_one_philo(t_philosopher *philo);
void	ft_update_meals_eaten(t_philosopher *philo);

/*ROUTINES*/
int		ft_think(t_philosopher *philo);
void	*routine(void *philo_ptr);
int		ft_sleep(t_philosopher *philo);

/*MONITORS*/
void	*ft_alive_monitor(void *data_ptr);
void	*ft_full_monitor(void *data_ptr);
int		ft_dead(t_philosopher *philo);
void	ft_notify_all(t_data *data);

/*UTILS_PRINT*/
int		ft_print_usage(void);
void	ft_check_validity(t_data *data);
void	ft_print_msg(t_data *data, int id, char *msg);

#endif