/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_forks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksansom <ksansom@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 13:28:02 by ksansom           #+#    #+#             */
/*   Updated: 2024/02/27 15:10:14 by ksansom          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

void	ft_drop_right(t_philosopher *philo)
{
	pthread_mutex_unlock(philo->right_fork);
}

void	ft_drop_forks(t_philosopher *philo)
{
	pthread_mutex_unlock(philo->left_fork);
	pthread_mutex_unlock(philo->right_fork);
}

int	ft_take_left(t_philosopher *philo)
{
	if (ft_dead(philo) || get_philo_state(philo) == DEAD)
		return (1);
	pthread_mutex_lock(philo->left_fork);
	ft_print_msg(philo->data, philo->id, "picked up a fork");
	return (0);
}

int	ft_take_right(t_philosopher *philo)
{
	if (ft_dead(philo) || get_philo_state(philo) == DEAD)
		return (1);
	pthread_mutex_lock(philo->right_fork);
	ft_print_msg(philo->data, philo->id, "picked up a fork");
	return (0);
}

int	ft_take_forks(t_philosopher *philo)
{
	if (get_num_philos(philo->data) == 1)
		return (ft_one_philo(philo));
	if (ft_take_right(philo))
		return (1);
	if (ft_take_left(philo))
	{
		ft_drop_right(philo);
		return (1);
	}
	return (0);
}
