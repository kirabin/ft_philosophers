#include "philo.h"

void	_sleep(t_philosopher *philo)
{
	pthread_mutex_lock(&philo->all->right_to_write);
	printf("%ld\tPhilosopher %d is sleeping\n", get_current_time(philo->all->start_time), philo->id);
	pthread_mutex_unlock(&philo->all->right_to_write);
	_usleep(philo->all->input.time_to_sleep, philo->all->start_time);
	(void)philo;
}
