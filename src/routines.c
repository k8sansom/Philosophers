/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routines.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksansom <ksansom@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 10:50:44 by ksansom           #+#    #+#             */
/*   Updated: 2024/02/23 14:08:34 by ksansom          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

int		ft_dead(t_philosopher *philo)
{
	t_data	*data;

	data = philo->data;
	if ((ft_get_time() - get_last_meal(philo)) > get_die_time(data) \
		&& get_philo_state(philo) != EATING)
	{
		set_philo_state(philo, DEAD);
		return (1);
	}
	return (0);
}

void	*routine(void *philo_ptr)
{
	t_philosopher	*philo;

	philo = (t_philosopher *)philo_ptr;
	ft_update_meal_time(philo);
	if (philo->id % 2 == 0)
		ft_usleep(philo->data->time_eat - 10);
	while (get_philo_state(philo) != DEAD)
	{
		if (ft_eat(philo) != 0)
			break ;
		if (get_philo_state(philo) == DEAD)
			break ;
		if (ft_sleep(philo) != 0)
			break ;
		if (get_philo_state(philo) == DEAD)
			break ;
		if (ft_think(philo) != 0)
			break ;
	}
	return (NULL);
}
