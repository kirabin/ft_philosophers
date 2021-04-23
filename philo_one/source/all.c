#include "philo_one.h"

void	free_all(t_all *all)
{
	if (all)
	{
		free(all->input);
	}
	free(all);
}

t_all	*init_all(long arg_len, char **args)
{
	t_all	*all;

	all = malloc(sizeof(all));
	if (all)
	{
		all->input = parce_input(arg_len, args);
		if (all->input)
		{
			all->start_time = get_start_time();
		}
		else
		{
			free_all(all);
			all = NULL;
		}
	}
	return (all);
}
