/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksansom <ksansom@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 13:12:50 by ksansom           #+#    #+#             */
/*   Updated: 2024/02/13 16:16:19 by ksansom          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

int	ft_malloc_init_data(t_data *data)
{

}

int	init_data(t_data *data, char **av)
{
	memset(data, 0, sizeof(t_data));
	data->num_philos = ft_atoi(av[1]);
	data->time_die = ft_atoi(av[2]);
	data->time_eat = ft_atoi(av[3]);
	data->time_sleep = ft_atoi(av[4]);
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
	pthread_mutex_init(&data->mut_eat NULL);
	pthread_mutex_init(&data->mut_sleep, NULL);
	pthread_mutex_init(&data->mut_die, NULL);
	pthread_mutex_init(&data->mut_print, NULL);
	pthread_mutex_init(&data->mut_num_philos, NULL);
	//pthread_mutex_init(&data->mut_keep_iter, NULL);
	pthread_mutex_init(&data->mut_start, NULL);
	//data->start_time = gettimeofday();
	return (ft_malloc_init_data(data));
}
