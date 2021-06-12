#include "philo.h"

int	get_philosophers_len(t_input *input, char *literal)
{
	int	philosophers_len;

	philosophers_len = ft_atoi(literal);
	if (philosophers_len <= 0)
	{
		printf("Should be positive number of philosophers\n");
		input->is_valid_input = false;
		return (0);
	}
	return (philosophers_len);
}

int	get_time_to_die(t_input *input, char *literal)
{
	long	time_to_die;

	time_to_die = ft_atoi(literal);
	if (time_to_die <= 0)
	{
		printf("Should be positive time to die\n");
		input->is_valid_input = false;
		return (0);
	}
	return (time_to_die);
}

int	get_time_to_eat(t_input *input, char *literal)
{
	long	time_to_eat;

	time_to_eat = ft_atoi(literal);
	if (time_to_eat <= 0)
	{
		printf("Should be positive time to eat\n");
		input->is_valid_input = false;
		return (0);
	}
	return (time_to_eat);
}

int	get_time_to_sleep(t_input *input, char *literal)
{
	long	time_to_sleep;

	time_to_sleep = ft_atoi(literal);
	if (time_to_sleep <= 0)
	{
		printf("Should be positive time to eat\n");
		input->is_valid_input = false;
		return (0);
	}
	return (time_to_sleep);
}

void	parce_input(t_input *input, long len, char **args)
{
	input->is_valid_input = false;
	if (len != 4 && len != 5)
		printf("Wrong arguments\n");
	else
	{
		input->philosophers_len = get_philosophers_len(input, *args++);
		input->time_to_die = get_time_to_die(input, *args++);
		input->time_to_eat = get_time_to_eat(input, *args++);
		input->time_to_sleep = get_time_to_sleep(input, *args++);
		if (!input->time_to_die || !input->philosophers_len
			|| !input->time_to_eat)
			return ;
		if (len == 5)
		{
			input->max_meals = ft_atoi(*args++);
			if (input->max_meals <= 0)
			{
				printf("Should be positive number of meals\n");
				input->is_valid_input = false;
				return ;
			}
		}
		input->is_valid_input = true;
	}
}
