/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routines.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksansom <ksansom@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 10:50:44 by ksansom           #+#    #+#             */
/*   Updated: 2024/03/12 15:25:11 by ksansom          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

int	ft_think(t_philosopher *philo)
{
	set_philo_state(philo, THINKING);
	if (get_philo_state(philo) == DEAD)
		return (1);
	ft_print_msg(philo->data, philo->id, "is thinking");
	return (0);
}

int	ft_sleep(t_philosopher *philo)
{
	set_philo_state(philo, SLEEPING);
	if (get_philo_state(philo) == DEAD)
		return (1);
	ft_print_msg(philo->data, philo->id, "is sleeping");
	ft_usleep(philo->data->time_sleep);
	return (0);
}

void	*routine(void *philo_ptr)
{
	t_philosopher	*philo;

	philo = (t_philosopher *)philo_ptr;
	ft_update_meal_time(philo);
	// if (philo->id % 2 == 0)
	// 	ft_usleep(philo->data->time_eat);
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
