/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksansom <ksansom@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 11:02:31 by ksansom           #+#    #+#             */
/*   Updated: 2024/02/16 11:24:09 by ksansom          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

int	main(int ac, char **av)
{
	t_data	data;

	memset(&data, 0, sizeof(t_data));
	if (ac <= 4 || ac >= 7)
		return (ft_print_usage());
	if (init_data(&data, av) != 0)
		return (ft_print_usage());
	if (init_malloc_data(&data) != 0)
		return (ft_error(&data, "Malloc error", 2));
	if (init_philosophers(&data) != 0)
		return (ft_error(&data, "Error initializing philosophers", 3));
	return (0);
}
