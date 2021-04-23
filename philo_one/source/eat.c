#include "philo_one.h"

void	eat_thread(t_all *all, t_philosopher philosopher)
{
	printf("%ld\tPhilosoppher %d is eating\n", get_current_time(all), philosopher.id);
	usleep(all->input->time_to_eat * 1000);
}
