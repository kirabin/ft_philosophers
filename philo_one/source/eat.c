#include "philo_one.h"

void	eat(t_all *all)
{
	// TODO: should we do mutex for this?
	print_current_time(all);
	printf("\tPhilosoppher %d is eating\n", all->philosopher.id);
	usleep(all->input->time_to_eat * 1000);
}
