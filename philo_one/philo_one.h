#ifndef PHILO_ONE_H
# define PHILO_ONE_H
# include <stdbool.h>
# include <sys/time.h>
# include <stdlib.h>
# include <limits.h>
# include <string.h>
# include <stdio.h>
# include <pthread.h>
# include <unistd.h>

typedef struct s_input
{
	int			philosophers_len;
	long		time_to_die;
	long		time_to_eat;
	long		time_to_sleep;
	int			max_meals;
}	t_input;

typedef struct s_philosopher
{
	pthread_t	thread_id;
	int			id;
}	t_philosopher;

typedef struct s_all
{
	long			start_time;
	t_philosopher	philosopher;
	t_input			*input;
}	t_all;

t_all		*init_all(long arg_len, char **args);
void		free_all(t_all *all);

void		free_input(t_input *input);
t_input		*parce_input(long argc, char **argv);
void		print_input(t_input *input);

long		get_start_time();
void		print_current_time(t_all *all);

void		eat(t_all *all);

long		ft_atoi(char *str);

#endif
