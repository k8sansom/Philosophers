/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksansom <ksansom@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 13:12:50 by ksansom           #+#    #+#             */
/*   Updated: 2024/02/13 13:32:25 by ksansom          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

void	init_data(t_data *data, char **av)
{
	int	i;

	i = -1;
	memset(data, 0, sizeof(t_data));
	while (av[++i])
		printf("%s\n", av[i]);
	//data->start_time = gettimeofday();
}
