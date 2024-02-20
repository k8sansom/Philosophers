#include "../inc/philo.h"

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
