#include "philo.h"

void	free_all(t_all *all)
{
	int	i;

	i = 0;
	if (all)
	{
		while (i < all->input.philosophers_len)
		{
			pthread_mutex_destroy(&all->forks[i]);
			pthread_mutex_destroy(&all->philosophers[i].right_to_eat);
			i++;
		}
		free(all->forks);
		free(all->philosophers);
	}
	pthread_mutex_destroy(&all->right_to_write);
}

void	assign_forks(t_philosopher *philosophers,
	pthread_mutex_t *forks, int i, int n)
{
	if (i == n - 1)
	{
		philosophers[i].highest_fork = &forks[i];
		philosophers[i].lowest_fork = &forks[0];
	}
	else
	{
		philosophers[i].lowest_fork = &forks[i];
		philosophers[i].highest_fork = &forks[i + 1];
	}
}

t_philosopher	*init_philosophers(int n,
	pthread_mutex_t *forks, t_all *all)
{
	int				i;
	t_philosopher	*philosophers;

	i = 0;
	philosophers = malloc(sizeof(t_philosopher) * n);
	while (i < n)
	{
		philosophers[i].id = i;
		philosophers[i].all = all;
		philosophers[i].eat_count = 0;
		pthread_mutex_init(&philosophers[i].right_to_eat, NULL);
		philosophers[i].right_to_write = &all->right_to_write;
		philosophers[i].die_time = all->input.time_to_die;
		assign_forks(philosophers, forks, i, n);
		i++;
	}
	return (philosophers);
}

pthread_mutex_t	*init_forks(int n)
{
	int					i;
	pthread_mutex_t		*forks;

	i = 0;
	forks = malloc(sizeof(pthread_mutex_t) * n);
	while (i < n)
	{
		pthread_mutex_init(&forks[i], NULL);
		i++;
	}
	return (forks);
}

void	init_all(t_all *all, long args_len, char **args)
{
	all->input.max_meals = INT_MAX;
	parce_input(&all->input, args_len, args);
	pthread_mutex_init(&all->right_to_write, NULL);
	all->start_time = get_start_time();
	all->forks = init_forks(all->input.philosophers_len);
	all->philosophers = init_philosophers(all->input.philosophers_len,
			all->forks, all);
}
