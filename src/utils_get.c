/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_get.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksansom <ksansom@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 13:00:06 by ksansom           #+#    #+#             */
/*   Updated: 2024/02/16 13:01:24 by ksansom          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

int	get_num_philos(t_data *data)
{
	int	num_philos;

	pthread_mutex_lock(&data->mut_num_philos);
	num_philos = data->num_philos;
	pthread_mutex_unlock(&data->mut_num_philos);
	return (num_philos);
}
