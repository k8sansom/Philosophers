/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksansom <ksansom@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 11:02:31 by ksansom           #+#    #+#             */
/*   Updated: 2024/02/27 15:30:13 by ksansom          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

static void	ft_join_threads(t_data *data)
{
	int	i;

	i = -1;
	if (pthread_join(data->check_all_alive, NULL))
		return ;
	if (data->num_meals > 0 && pthread_join(data->check_all_full, NULL))
		return ;
	while (++i < data->num_philos)
	{
		if (pthread_join(data->philo_threads[i], NULL))
			return ;
	}
	return ;
}

static void	ft_run_threads(t_data *data)
{
	int		i;

	data->time_start = ft_get_time();
	i = -1;
	while (++i < data->num_philos)
	{
		if (pthread_create(&data->philo_threads[i], NULL, &routine, \
			&data->philosophers[i]))
			return ;
	}
	if (pthread_create(&data->check_all_alive, NULL, \
		&ft_alive_monitor, data))
		return ;
	if (data->num_meals != -1
		&& pthread_create(&data->check_all_full, NULL, \
		&ft_full_monitor, data))
		return ;
	return ;
}

int	main(int ac, char **av)
{
	t_data	data;

	memset(&data, 0, sizeof(t_data));
	if (ft_input_check(ac, av) != 0)
		return (ft_print_usage());
	if (init_data(&data, av) != 0)
		return (2);
	init_philosophers(&data);
	ft_run_threads(&data);
	ft_join_threads(&data);
	ft_free(&data);
	return (0);
}
