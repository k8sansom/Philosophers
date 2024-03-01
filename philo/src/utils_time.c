/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_time.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksansom <ksansom@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 10:25:49 by ksansom           #+#    #+#             */
/*   Updated: 2024/02/23 15:25:11 by ksansom          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

void	ft_usleep(size_t time_sleep)
{
	size_t	start;

	start = ft_get_time();
	while ((ft_get_time() - start) < time_sleep)
		usleep(500);
}

void	ft_update_meal_time(t_philosopher *philo)
{
	pthread_mutex_lock(&philo->mut_last_meal_time);
	philo->last_meal_time = ft_get_time();
	pthread_mutex_unlock(&philo->mut_last_meal_time);
}

size_t	ft_get_time(void)
{
	struct timeval	time;

	if (gettimeofday(&time, NULL))
		return (0);
	return ((size_t)((time.tv_sec * 1000) + (time.tv_usec / 1000)));
}
