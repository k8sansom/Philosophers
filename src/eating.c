/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eating.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksansom <ksansom@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 10:22:38 by ksansom           #+#    #+#             */
/*   Updated: 2024/02/16 10:25:07 by ksansom          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

void	ft_update_meal_time(t_philosopher *philo)
{
	pthread_mutex_lock(&philo->mut_last_meal_time);
	philo->last_meal_time = ft_get_time();
	pthread_mutex_unlock(&philo->mut_last_meal_time);
}