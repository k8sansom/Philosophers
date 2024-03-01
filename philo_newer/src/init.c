/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksansom <ksansom@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 13:12:50 by ksansom           #+#    #+#             */
/*   Updated: 2024/02/27 15:30:05 by ksansom          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"


void	init_forks(t_data *data)
{
	t_philosopher	*philo;
	pthread_mutex_t	forks[data->num_philos];
	int				i;

	philo = data->philosophers;
	memset(&forks, 0, sizeof(pthread_mutex_t) * data->num_philos);
	data->forks = forks;
	i = 0;
	while (i < data->num_philos)
	{
		pthread_mutex_init(&data->forks[i], NULL);
		i++;
	}
	i = 0;
	philo[0].left_fork = &data->forks[0];
	philo[0].right_fork = &data->forks[data->num_philos - 1];
	while (++i < data->num_philos)
	{
		philo[i].left_fork = &data->forks[i];
		philo[i].right_fork = &data->forks[i - 1];
	}
}

void	init_philosophers(t_data *data)
{
	t_philosopher	philosophers[data->num_philos];
	int				i;

	i = 0;
	memset(&philosophers, 0, sizeof(t_philosopher) * data->num_philos);
    data->philosophers = philosophers;
	while (i < data->num_philos)
	{
		philosophers[i].data = data;
		philosophers[i].id = i + 1;
		printf("%d\n", philosophers[i].id);
		philosophers[i].state = IDLE;
		pthread_mutex_init(&philosophers[i].mut_state, NULL);
		pthread_mutex_init(&philosophers[i].mut_meals_eaten, NULL);
		pthread_mutex_init(&philosophers[i].mut_last_meal_time, NULL);
		ft_update_meal_time(&philosophers[i]);
		i++;
	}
	init_forks(data);
}

int	init_data(t_data *data, char **av)
{
	data->num_philos = ft_atoi(av[1]);
	data->time_die = (size_t)ft_atoi(av[2]);
	data->time_eat = (size_t)ft_atoi(av[3]);
	data->time_sleep = (size_t)ft_atoi(av[4]);
	data->keep_loop = 1;
	data->num_meals = -1;
	if (av[5])
		data->num_meals = ft_atoi(av[5]);
	ft_check_validity(data);
	pthread_mutex_init(&data->mut_print, NULL);
	pthread_mutex_init(&data->mut_keep_loop, NULL);
	return (0);
}
