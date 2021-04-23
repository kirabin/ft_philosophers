#include "philo_one.h"

void	free_input(t_input *input)
{
	free(input);
}

t_input	*parce_input(long len, char **args)
{
	t_input	*input;

	if (len != 4 && len != 5)
	{
		printf("Wrong arguments\n");
		return (NULL);
	}
	input = malloc(sizeof(t_input));
	if (input)
	{
		input->philosophers_len = ft_atoi(*args++);
		input->time_to_die = ft_atoi(*args++);
		input->time_to_eat = ft_atoi(*args++);
		input->time_to_sleep = ft_atoi(*args++);
		if (len == 5)
			input->max_meals = ft_atoi(*args++);
		else
			input->max_meals = INT_MAX;
	}
	return (input);
}

void	print_input(t_input *input)
{
	if (input)
	{
		printf("%d\n", input->philosophers_len);
		printf("%ld\n", input->time_to_die);
		printf("%ld\n", input->time_to_eat);
		printf("%ld\n", input->time_to_sleep);
		printf("%d\n", input->max_meals);
	}
}
