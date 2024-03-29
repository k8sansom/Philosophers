/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_get.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksansom <ksansom@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 13:00:06 by ksansom           #+#    #+#             */
/*   Updated: 2024/03/01 10:50:34 by ksansom          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

int	get_meals_eaten(t_philosopher *philo)
{
	int		meals_eaten;

	pthread_mutex_lock(&philo->mut_meals_eaten);
	meals_eaten = philo->meals_eaten;
	pthread_mutex_unlock(&philo->mut_meals_eaten);
	return (meals_eaten);
}

size_t	get_last_meal(t_philosopher *philo)
{
	size_t	last_meal_time;

	pthread_mutex_lock(&philo->mut_last_meal_time);
	last_meal_time = philo->last_meal_time;
	pthread_mutex_unlock(&philo->mut_last_meal_time);
	return (last_meal_time);
}

int	get_keep_loop(t_data *data)
{
	int	keep_looping;

	pthread_mutex_lock(&data->mut_keep_loop);
	keep_looping = data->keep_loop;
	pthread_mutex_unlock(&data->mut_keep_loop);
	return (keep_looping);
}

t_state	get_philo_state(t_philosopher *philo)
{
	t_state	state;

	pthread_mutex_lock(&philo->mut_state);
	state = philo->state;
	pthread_mutex_unlock(&philo->mut_state);
	return (state);
}
