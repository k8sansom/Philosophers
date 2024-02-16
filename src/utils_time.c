/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_time.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksansom <ksansom@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 10:25:49 by ksansom           #+#    #+#             */
/*   Updated: 2024/02/16 11:25:39 by ksansom          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

void	ft_update_meal_time(t_philosopher *philo)
{
	pthread_mutex_lock(&philo->mut_last_meal_time);
	philo->last_meal_time = ft_get_time();
	pthread_mutex_unlock(&philo->mut_last_meal_time);
}

unsigned long	ft_get_time(void)
{
	struct timeval	time;

	if (gettimeofday(&time, NULL))
		return (0);
	return ((unsigned long)((time.tv_sec * 1000) + (time.tv_usec / 1000)));
}
