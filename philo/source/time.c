#include "philo.h"

long	get_start_time()
{
	struct timeval	tp_start;

	gettimeofday(&tp_start, NULL);
	printf("start_ms: %ld\n", tp_start.tv_sec * 1000 + tp_start.tv_usec / 1000);
	return (tp_start.tv_sec * 1000 + tp_start.tv_usec / 1000);
}

long	get_current_time(long start_time)
{
	struct timeval	tp_start;
	long			current_time;

	gettimeofday(&tp_start, NULL);
	current_time =  tp_start.tv_sec * 1000 + tp_start.tv_usec / 1000;
	return (current_time - start_time);
}
