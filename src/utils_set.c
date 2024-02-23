/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_set.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksansom <ksansom@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 14:09:07 by ksansom           #+#    #+#             */
/*   Updated: 2024/02/23 14:43:59 by ksansom          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

void	set_keep_loop(t_data *data, int set_to)
{
	pthread_mutex_lock(&data->mut_keep_loop);
	data->keep_loop = set_to;
	pthread_mutex_unlock(&data->mut_keep_loop);
}

void	set_philo_state(t_philosopher *philo, t_state state)
{
	pthread_mutex_lock(&philo->mut_state);
	if (philo->state != DEAD)
		philo->state = state;
	pthread_mutex_unlock(&philo->mut_state);
}

