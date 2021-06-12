#include "philo.h"

bool	should_philo_die(t_all *all, int i)
{
	if (all->philosophers[i].die_time < get_current_time(all->start_time))
	{
		pthread_mutex_lock(&all->right_to_write);
		printf("%ld\tPhilosopher %d is dead\n",
			get_current_time(all->start_time), i + 1);
		return (true);
	}
	return (false);
}

void	*observe(void *arg)
{
	int		i;
	t_all	*all;
	int		full_philosophers;

	all = (t_all *)arg;
	while (1)
	{
		i = -1;
		full_philosophers = 0;
		while (++i < all->input.philosophers_len)
		{
			pthread_mutex_lock(&all->philosophers[i].right_to_eat);
			if (all->philosophers[i].eat_count >= all->input.max_meals)
				full_philosophers++;
			if (should_philo_die(all, i))
				return (0);
			pthread_mutex_unlock(&all->philosophers[i].right_to_eat);
		}
		if (full_philosophers == all->input.philosophers_len)
		{
			pthread_mutex_lock(&all->right_to_write);
			return (0);
		}
	}
}

void	*function(void *arg)
{
	t_philosopher	*me;

	me = (t_philosopher *)arg;
	while (1)
	{
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
		if (pthread_create(&thread_id, NULL,
				function, all->philosophers + i) == -1)
		{
			pthread_mutex_lock(&all->right_to_write);
			printf("Couldn't create thread\n");
			return ;
		}
		pthread_detach(thread_id);
		i++;
	}
	observe(all);
}

int	main(int argc, char **argv)
{
	t_all	all;

	init_all(&all, argc - 1, argv + 1);
	if (all.input.is_valid_input)
		start_threads(&all);
	free_all(&all);
	return (0);
}
