/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksansom <ksansom@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 13:12:50 by ksansom           #+#    #+#             */
/*   Updated: 2024/02/16 11:30:24 by ksansom          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

int	init_philosophers(t_data *data)
{
	t_philosopher	*philo;
	int				i;

	i = 0;
	philo = data->philosophers;
	while (i < data->num_philos)
	{
		philo[i].id = i + 1;
		philo[i].meals_eaten = 0;
		philo[i].state = IDLE;
		pthread_mutex_init(&philo[i].mut_state, NULL);
		pthread_mutex_init(&philo[i].mut_meals_eaten, NULL);
		pthread_mutex_init(&philo[i].mut_last_meal_time, NULL);
		ft_update_meal_time(&philo[i]);
		if (philo->last_meal_time == 0)
			return (3);
		i++;
	}
	return (0);
}

int	init_malloc_data(t_data *data)
{
	data->philosophers = malloc(sizeof(t_philosopher) * data->num_philos);
	if (data->philosophers == NULL)
		return (2);
	data->forks = malloc(sizeof(pthread_mutex_t) * data->num_philos);
	if (data->forks == NULL)
		return (2);
	data->philo_threads = malloc(sizeof(pthread_t) * data->num_philos);
	if (data->philo_threads == NULL)
		return (2);
	return (0);
}

int	init_data(t_data *data, char **av)
{
	data->num_philos = ft_atoi(av[1]);
	data->time_die = (unsigned long)ft_atoi(av[2]);
	data->time_eat = (unsigned long)ft_atoi(av[3]);
	data->time_sleep = (unsigned long)ft_atoi(av[4]);
	if (av[5])
	{
		data->num_meals = ft_atoi(av[5]);
		if (data->num_meals <= 0)
			return (1);
	}
	if (data->num_philos < 1 || data->num_philos > 200)
		return (1);
	if (data->time_eat < 60 || data->time_die < 60 || data->time_sleep < 60)
		return (1);
	pthread_mutex_init(&data->mut_eat, NULL);
	pthread_mutex_init(&data->mut_sleep, NULL);
	pthread_mutex_init(&data->mut_die, NULL);
	pthread_mutex_init(&data->mut_print, NULL);
	pthread_mutex_init(&data->mut_num_philos, NULL);
	//pthread_mutex_init(&data->mut_keep_iter, NULL);
	pthread_mutex_init(&data->mut_start, NULL);
	data->time_start = ft_get_time();
	printf("start time: %lu\n", data->time_start);
	return (0);
}
