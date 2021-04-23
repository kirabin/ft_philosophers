#include "philo_one.h"

void	sleep_thread(t_all *all, t_philosopher philosopher)
{
	printf("%ld\tPhilosoppher %d is sleeping\n", get_current_time(all), philosopher.id);
	usleep(all->input->time_to_sleep * 1000);
}
