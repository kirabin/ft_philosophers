#include "philo.h"

void	_usleep(int milliseconds, int start_time)
{
	time_t	stop;
	time_t	start;

	stop = get_current_time(start_time) + milliseconds;
	start = get_current_time(start_time);
	while (start < stop)
	{
		usleep(50);
		start = get_current_time(start_time);
	}
}

long	ft_atoi(char *str)
{
	long	res;

	res = 0;
	while (*str)
	{
		if ('0' <= *str && *str <= '9')
			res = res * 10 + (*str - '0');
		else
			break ;
		str++;
	}
	return (res);
}
