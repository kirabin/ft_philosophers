#include "philo_one.h"

void	eat(t_all *all)
{
	// TODO: should we do mutex for this?
	printf("%ld\tPhilosoppher %d is eating\n",get_current_time(all), all->philosopher.id);
	usleep(all->input->time_to_eat * 1000);
}
