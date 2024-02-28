/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_print.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksansom <ksansom@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 10:40:56 by ksansom           #+#    #+#             */
/*   Updated: 2024/02/23 15:49:04 by ksansom          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

void	ft_print_msg(t_data *data, int id, char *msg)
{
	size_t	time;

	time = ft_get_time() - data->time_start;
	pthread_mutex_lock(&data->mut_print);
	if (get_keep_loop(data))
		printf("%zu philosopher %d %s\n", time, id, msg);
	pthread_mutex_unlock(&data->mut_print);
}

void	ft_check_validity(t_data *data)
{
	size_t	d;
	size_t	e;
	size_t	s;

	d = data->time_die;
	e = data->time_eat;
	s = data->time_sleep;
	if (data->num_philos == 1)
		printf("A philosopher can't eat with only one fork :(\n");
	else if (data->num_philos % 2 == 0)
	{
		if (d < (e + s + 10))
			printf("Warning: not enough time, a philosopher will die :(\n");
	}
	else
	{
		if (d < ((e * 2) + s + 10))
			printf("Warning: not enough time, a philosopher will die :(\n");
	}
}

int	ft_print_usage(void)
{
	write(1, "\nIMPROPER USAGE:\n", 17);
	write(1, "./philo #philosophers time_to_die ", 34);
	write(1, "time_to_eat time_to_sleep ", 26);
	write(1, "(optional)#meals\n\n", 18);
	write(1, "Example:\n", 9);
	write(1, "./philo 4 800 200 200 5\n\n", 25);
	write(1, "#philosophers: 1-200\n", 21);
	write(1, "time_to_die: 60+\n", 17);
	write(1, "time_to_eat: 60+\n", 17);
	write(1, "time_to_sleep: 60+\n", 19);
	write(1, "#meals: 1+\n\n", 12);
	return (1);
}
