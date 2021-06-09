#include "philo.h"

long	ft_atoi(char *str)
{
	long		res;

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
