#include "../inc/philo.h"

void ft_check_validity(t_data *data)
{
	int	d;
	int	e;
	int	s;

	d = data->time_die;
	e = data->time_eat;
	s = data->time_sleep;
	if (data->num_philos % 2 == 0)
	{
		if (d < (e + s + 10))
			printf("Warning: there is not enough time, a philosopher will die :(\n");
	}
	else
	{
		if (d < ((e * 2) + s + 10))
			printf("Warning: there is not enough time, a philosopher will die :(\n");
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
