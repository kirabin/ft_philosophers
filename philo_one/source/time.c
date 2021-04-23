#include "philo_one.h"

long	get_start_time()
{
	struct timeval	tp_start;

	gettimeofday(&tp_start, NULL);
	printf("start_ms: %ld\n", tp_start.tv_sec * 1000 + tp_start.tv_usec / 1000);
	return (tp_start.tv_usec / 1000);
}

void	print_current_time(t_all *all)
{
	struct timeval	tp_start;
	long			current_time;

	gettimeofday(&tp_start, NULL);
	current_time =  tp_start.tv_sec * 1000 + tp_start.tv_usec / 1000;
	printf("%ld", current_time - all->start_time);
}
