#include "philo.h"

void	free_input(t_input *input)
{
	free(input);
}

void parce_input(t_input *input, long len, char **args)
{
	if (len != 4 && len != 5)
	{
		printf("Wrong arguments\n");
	}
	input->philosophers_len = ft_atoi(*args++);
	// TODO: negative philosophers;
	input->time_to_die = ft_atoi(*args++);
	input->time_to_eat = ft_atoi(*args++);
	input->time_to_sleep = ft_atoi(*args++);
	if (len == 5)
		input->max_meals = ft_atoi(*args++);
	else
		input->max_meals = INT_MAX;

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
