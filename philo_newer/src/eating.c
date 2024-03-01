/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eating.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksansom <ksansom@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 10:22:38 by ksansom           #+#    #+#             */
/*   Updated: 2024/02/27 13:36:00 by ksansom          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

int	ft_take_forks(t_philosopher *philo)
{
	if (philo->data->num_philos == 1)
		return (ft_one_philo(philo));
	if (ft_dead(philo) || get_philo_state(philo) == DEAD)
		return (1);
	pthread_mutex_lock(philo->right_fork);
	ft_print_msg(philo->data, philo->id, "has taken a fork");
	if (ft_dead(philo) || get_philo_state(philo) == DEAD)
	{
		pthread_mutex_unlock(philo->right_fork);
		return (1);
	}
	pthread_mutex_lock(philo->left_fork);
	ft_print_msg(philo->data, philo->id, "has taken a fork");
	return (0);
}

int	ft_one_philo(t_philosopher *philo)
{
	if (ft_dead(philo) || get_philo_state(philo) == DEAD)
		return (1);
	pthread_mutex_lock(philo->left_fork);
	ft_print_msg(philo->data, philo->id, "picks up left fork");
	ft_usleep(philo->data->time_die);
	set_philo_state(philo, DEAD);
	return (1);
}

void	ft_update_meals_eaten(t_philosopher *philo)
{
	pthread_mutex_lock(&philo->mut_meals_eaten);
	philo->meals_eaten++;
	pthread_mutex_unlock(&philo->mut_meals_eaten);
}

int	ft_eat(t_philosopher *philo)
{
	if (ft_take_forks(philo) != 0)
		return (1);
	set_philo_state(philo, EATING);
	ft_print_msg(philo->data, philo->id, "is eating");
	ft_update_meal_time(philo);
	ft_usleep(philo->data->time_eat);
	ft_update_meals_eaten(philo);
	pthread_mutex_unlock(philo->left_fork);
	pthread_mutex_unlock(philo->right_fork);
	return (0);
}
