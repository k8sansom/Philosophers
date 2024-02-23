/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitors.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksansom <ksansom@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 12:24:36 by ksansom           #+#    #+#             */
/*   Updated: 2024/02/23 15:48:45 by ksansom          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

void	*ft_full_monitor(void *data_ptr)
{
	int		i;
	
}

void	*ft_alive_monitor(void *data_ptr)
{
	int				i;
	int				num_philos;
	t_data			*data;
	t_philosopher	*philo;

	data = (t_data *)data_ptr;
	philo = data->philosophers;
	num_philos = get_num_philos(data);
	i = -1;
	while (++i < num_philos && get_keep_loop(data))
	{
		if (ft_dead(&philo[i]) && get_keep_loop(data))
		{
			ft_print_msg(data, philo[i].id, "died");
			set_keep_loop(data, 0);
			ft_notify_all(data);
			break ;
		}
		if (i == num_philos - 1)
			i = -1;
		usleep(1000);
	}
	return (NULL);
}