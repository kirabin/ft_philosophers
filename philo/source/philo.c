#include "philo.h"

// LEARN:	What is mutex?

void	*observe(void *arg)
{
	int		i;
	t_all	*all;
	int		full_philosophers;


	all = (t_all *)arg;
	while (1)
	{
		i = 0;
		full_philosophers = 0;
		while (i < all->input.philosophers_len)
		{
			pthread_mutex_lock(&all->philosophers[i].right_to_eat);
			if (all->philosophers[i].eat_count >= all->input.max_meals)
				full_philosophers++;
			if (all->philosophers[i].die_time < get_current_time(all->start_time)) {
				pthread_mutex_lock(&all->right_to_write);
				printf("%ld\tPhilosopher %d is dead, die time %ld\n", get_current_time(all->start_time), i, all->philosophers[i].die_time);
				return (0);
				// pthread_mutex_unlock(&all->right_to_write);
			}
			pthread_mutex_unlock(&all->philosophers[i].right_to_eat);
			i++;
		}
		if (full_philosophers == all->input.philosophers_len)
		{
			pthread_mutex_lock(&all->right_to_write);
			printf("\t\tPhilosophers are full\n");
			return (0);
			pthread_mutex_unlock(&all->right_to_write);
		}
		// i = 0;
		// while (i < all->input.philosophers_len)
		// {
		// 	i++;
		// }
	}
}

void	*function(void *arg)
{
	t_philosopher	*me;

	me = (t_philosopher *)arg;
	// pthread_mutex_lock(&me->all->right_to_write);
	// printf("%ld\tPhilosopher %d is created\n", get_current_time(me->all->start_time), me->id);
	// pthread_mutex_unlock(&me->all->right_to_write);
	while (1) {
		take_forks(me);
		eat(me);
		_sleep(me);
		think(me);
	}
	return (NULL);
}

void	start_threads(t_all *all)
{
	int			i;
	pthread_t	thread_id;

	i = 0;
	pthread_mutex_lock(&all->right_to_write);
	printf("Before\n");
	pthread_mutex_unlock(&all->right_to_write);
	while (i < all->input.philosophers_len)
	{
		if (pthread_create(&thread_id, NULL, function, all->philosophers + i) == -1) {
			// error;
			break;
		}
		pthread_detach(thread_id);
		i++;
	}
	// if (pthread_create(&thread_id, NULL, observe, all) == -1) {
	// 	// error;
	// }
	observe(all);
	// pthread_join(thread_id, NULL);
	// pthread_mutex_lock(&all->right_to_write);
	// printf("After\n");
	// pthread_mutex_unlock(&all->right_to_write);
}

int	main(int argc, char **argv)
{
	t_all	all;

	init_all(&all, argc - 1, argv + 1);
	start_threads(&all);
	free_all(&all);
	return (0);
}
