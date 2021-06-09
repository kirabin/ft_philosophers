#include "philo.h"

// LEARN:	What is mutex?

void	*function(void *arg)
{
	t_philosopher	*me;

	me = (t_philosopher *)arg;
	pthread_mutex_lock(&me->all->right_to_write);
	printf("%ld\tPhilosoppher %d is created\n", get_current_time(me->all), me->id);
	pthread_mutex_unlock(&me->all->right_to_write);
	// eat_thread(all, philosopher);
	// sleep_thread(all, philosopher);
	return (NULL);
}

// void log_message(messege)
// {
// 	static time_t	start;
// }

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
	pthread_mutex_lock(&all->right_to_write);
	printf("After\n");
	pthread_mutex_unlock(&all->right_to_write);
}

int	main(int argc, char **argv)
{
	t_all	all;

	init_all(&all, argc - 1, argv + 1);
	start_threads(&all);
	free_all(&all);
	return (0);
}
