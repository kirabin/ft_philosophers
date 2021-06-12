#include "philo.h"

void	take_forks(t_philosopher *philo)
{
	pthread_mutex_lock(philo->lowest_fork);
	pthread_mutex_lock(&philo->all->right_to_write);
	printf("%ld\tPhilosopher %d took lowest fork\n",
		get_current_time(philo->all->start_time), philo->id + 1);
	pthread_mutex_unlock(&philo->all->right_to_write);
	pthread_mutex_lock(philo->highest_fork);
	pthread_mutex_lock(&philo->all->right_to_write);
	printf("%ld\tPhilosopher %d took highest fork\n",
		get_current_time(philo->all->start_time), philo->id + 1);
	pthread_mutex_unlock(&philo->all->right_to_write);
}

void	eat(t_philosopher *philo)
{
	pthread_mutex_lock(&philo->right_to_eat);
	pthread_mutex_lock(&philo->all->right_to_write);
	printf("%ld\tPhilosopher %d is eating\n",
		get_current_time(philo->all->start_time), philo->id + 1);
	pthread_mutex_unlock(&philo->all->right_to_write);
	philo->eat_count++;
	philo->die_time = get_current_time(philo->all->start_time)
		+ philo->all->input.time_to_die;
	pthread_mutex_unlock(&philo->right_to_eat);
	_usleep(philo->all->input.time_to_eat, philo->all->start_time);
	pthread_mutex_unlock(philo->lowest_fork);
	pthread_mutex_unlock(philo->highest_fork);
}

void	think(t_philosopher *philo)
{
	pthread_mutex_lock(&philo->all->right_to_write);
	printf("%ld\tPhilosopher %d is thinking\n",
		get_current_time(philo->all->start_time), philo->id + 1);
	pthread_mutex_unlock(&philo->all->right_to_write);
}
