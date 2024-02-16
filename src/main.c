/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksansom <ksansom@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 11:02:31 by ksansom           #+#    #+#             */
/*   Updated: 2024/02/16 13:39:44 by ksansom          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

/*static void	ft_run_threads(t_data *data)
{
	int		i;
	int		num_philos;

	num_philos = get_num_philos(data);
	i = -1;
	while (++i < num_philos)
	{
		if (pthread_create(&data->philo_threads[i], NULL, &routine, \
			&data->philosophers[i]))
			return ;
	}
}*/

int	main(int ac, char **av)
{
	t_data	data;

	memset(&data, 0, sizeof(t_data));
	if (ac <= 4 || ac >= 7)
		return (ft_print_usage());
	if (init_data(&data, av) != 0)
		return (ft_print_usage());
	if (init_malloc_data(&data) != 0)
		return (ft_exit(&data, "Malloc error", 2));
	init_philosophers(&data);
	//ft_run_threads(&data);
	//ft_join_threads(&data);
	free_phil_data(&data);
	return (ft_exit(&data, "All done!\n", 0));
}
