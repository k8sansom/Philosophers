/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitors.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksansom <ksansom@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 12:24:36 by ksansom           #+#    #+#             */
/*   Updated: 2024/02/27 13:24:42 by ksansom          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

int	ft_dead(t_philosopher *philo)
{
	t_data	*data;

	data = philo->data;
	if ((ft_get_time() - get_last_meal(philo)) > data->time_die \
		&& get_philo_state(philo) != EATING)
	{
		set_philo_state(philo, DEAD);
		return (1);
	}
	return (0);
}

void	ft_notify_all(t_data *data)
{
	t_philosopher	*philo;
	int				i;

	philo = data->philosophers;
	i = 0;
	while (i < data->num_philos)
	{
		set_philo_state(&philo[i], DEAD);
		i++;
	}
}

void	*ft_full_monitor(void *data_ptr)
{
	int		i;
	t_data	*data;

	data = (t_data *)data_ptr;
	i = -1;
	while ((++i < data->num_philos) && get_keep_loop(data))
	{
		usleep(1000);
		if (get_meals_eaten(&data->philosophers[i]) < data->num_meals)
			i = -1;
	}
	if (get_keep_loop(data))
	{
		set_keep_loop(data, 0);
		ft_notify_all(data);
	}
	return (NULL);
}

void	*ft_alive_monitor(void *data_ptr)
{
	int				i;
	t_data			*data;
	t_philosopher	*philo;

	data = (t_data *)data_ptr;
	philo = data->philosophers;
	i = -1;
	while (++i < data->num_philos && get_keep_loop(data))
	{
		if (ft_dead(&philo[i]) && get_keep_loop(data))
		{
			ft_print_msg(data, philo[i].id, "died");
			set_keep_loop(data, 0);
			ft_notify_all(data);
			break ;
		}
		if (i == data->num_philos - 1)
			i = -1;
		usleep(1000);
	}
	return (NULL);
}