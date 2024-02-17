/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksansom <ksansom@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 16:02:17 by ksansom           #+#    #+#             */
/*   Updated: 2024/02/16 13:15:23 by ksansom          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

void	free_phil_data(t_data *data)
{
	int	i;
	int	num_philos;

	num_philos = get_num_philos(data);
	i = 0;
	while (i < num_philos)
	{
		pthread_mutex_destroy(&data->forks[i]);
		pthread_mutex_destroy(&data->philosophers[i].mut_state);
		pthread_mutex_destroy(&data->philosophers[i].mut_meals_eaten);
		pthread_mutex_destroy(&data->philosophers[i].mut_last_meal_time);
		i++;
	}
	pthread_mutex_destroy(&data->mut_time_die);
	pthread_mutex_destroy(&data->mut_time_eat);
	pthread_mutex_destroy(&data->mut_time_sleep);
	pthread_mutex_destroy(&data->mut_num_philos);
	pthread_mutex_destroy(&data->mut_print);
	pthread_mutex_destroy(&data->mut_keep_loop);
	pthread_mutex_destroy(&data->mut_time_start);
	free(data->philo_threads);
	free(data->philosophers);
	free(data->forks);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	ft_exit(t_data *data, char *str, int ret_code)
{
	if (ret_code == 2)
	{
		if (data->forks)
			free(data->forks);
		if (data->philo_threads)
			free(data->philo_threads);
		if (data->philosophers)
			free(data->philosophers);
	}
	if (str)
		write(1, str, ft_strlen(str));
	return (ret_code);
}

int	ft_atoi(char *str)
{
	int	i;
	int	sign;
	int	result;

	i = 0;
	sign = 1;
	result = 0;
	while (str[i] && (str[i] == ' ' || str[i] == '\t' || str[i] == '\n' \
		|| str[i] == '\r' || str[i] == '\f' || str[i] == '\v'))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + (str[i] - '0');
		i++;
	}
	return (result * sign);
}
