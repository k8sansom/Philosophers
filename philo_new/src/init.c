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

int	ft_input_check(int ac, char **av)
{
	int		check;

	check = 0;
	if (ac < 5 || ac > 6)
		return (1);
	if (ft_isdigit(ac, av) != 0)
		return (1);
	if (av[5])
	{
		if (ft_atoi(av[5]) <= 0)
			return (1);
	}
	check = ft_atoi(av[1]);
	if (check < 1 || check > 200)
		return (1);
	if (ft_atoi(av[2]) < 60 || ft_atoi(av[3]) < 60 || ft_atoi(av[4]) < 60)
		return (1);
	return (0);
}

void	init_forks(t_data *data)
{
	t_philosopher	*philo;
	int				i;

	philo = data->philosophers;
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
	t_philosopher	*philo;
	int				i;

	i = 0;
	philo = data->philosophers;
	while (i < data->num_philos)
	{
		philo[i].data = data;
		philo[i].id = i + 1;
		philo[i].meals_eaten = 0;
		philo[i].state = IDLE;
		pthread_mutex_init(&philo[i].mut_state, NULL);
		pthread_mutex_init(&philo[i].mut_meals_eaten, NULL);
		pthread_mutex_init(&philo[i].mut_last_meal_time, NULL);
		ft_update_meal_time(&philo[i]);
		i++;
	}
	init_forks(data);
}

int	init_malloc_data(t_data *data)
{
	data->philosophers = malloc(sizeof(t_philosopher) * data->num_philos);
	if (data->philosophers == NULL)
		return (2);
	data->forks = malloc(sizeof(pthread_mutex_t) * data->num_philos);
	if (data->forks == NULL)
		return (free(data->philosophers), 2);
	data->philo_threads = malloc(sizeof(pthread_t) * data->num_philos);
	if (data->philo_threads == NULL)
		return (free(data->philosophers), free(data->forks), 2);
	return (0);
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
	pthread_mutex_init(&data->mut_time_eat, NULL);
	pthread_mutex_init(&data->mut_time_sleep, NULL);
	pthread_mutex_init(&data->mut_time_die, NULL);
	pthread_mutex_init(&data->mut_print, NULL);
	pthread_mutex_init(&data->mut_num_philos, NULL);
	pthread_mutex_init(&data->mut_keep_loop, NULL);
	pthread_mutex_init(&data->mut_time_start, NULL);
	return (init_malloc_data(data));
}
