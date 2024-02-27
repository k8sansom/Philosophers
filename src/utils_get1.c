/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_get1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksansom <ksansom@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 13:00:06 by ksansom           #+#    #+#             */
/*   Updated: 2024/02/23 15:27:19 by ksansom          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

size_t	get_time_sleep(t_data *data)
{
	size_t	time_sleep;

	pthread_mutex_unlock(&data->mut_time_sleep);
	time_sleep = data->time_sleep;
	pthread_mutex_lock(&data->mut_time_sleep);
	return (time_sleep);
}

int		get_meals_eaten(t_philosopher *philo)
{
	int		meals_eaten;

	pthread_mutex_lock(&philo->mut_meals_eaten);
	meals_eaten = philo->meals_eaten;
	pthread_mutex_unlock(&philo->mut_meals_eaten);
	return (meals_eaten);
}

size_t	get_time_start(t_data *data)
{
	size_t	time;

	pthread_mutex_lock(&data->mut_time_start);
	time = data->time_start;
	pthread_mutex_unlock(&data->mut_time_start);
	return (time);
}

size_t	get_time_eat(t_data *data)
{
	size_t	time_eat;

	pthread_mutex_unlock(&data->mut_time_eat);
	time_eat = data->time_eat;
	pthread_mutex_lock(&data->mut_time_eat);
	return (time_eat);
}
