/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksansom <ksansom@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 11:02:31 by ksansom           #+#    #+#             */
/*   Updated: 2024/02/13 15:55:14 by ksansom          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

int	main(int ac, char **av)
{
	t_data	data;

	if (ac <= 4 || ac >= 7)
	{
		ft_print_usage();
		return (1);
	}
	if (init_data(&data, av) != 0)
	{
		ft_print_usage();
		return (1);
	}
	return (0);
}
