#ifndef PHILO_H
# define PHILO_H
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

typedef struct s_all	t_all;

typedef struct s_philosopher
{
	int				id;
	pthread_mutex_t	*highest_fork;
	pthread_mutex_t	*lowest_fork;
	pthread_mutex_t	*right_to_write;
	time_t			die_time;
	int				eat_count;
	pthread_mutex_t	right_to_eat;
	t_all			*all;
}	t_philosopher;

typedef struct s_all
{
	long			start_time;
	int				current_number;
	pthread_mutex_t	*forks;
	pthread_mutex_t	right_to_write;
	t_philosopher	*philosophers;
	t_input			input;

}	t_all;

void		init_all(t_all *all, long arg_len, char **args);
void		free_all(t_all *all);

void		free_input(t_input *input);
void		parce_input(t_input *input, long argc, char **argv);
void		print_input(t_input *input);

long		get_start_time();
long		get_current_time(t_all *all);

void		eat_thread(t_all *all, t_philosopher philosopher);
void		sleep_thread(t_all *all, t_philosopher philosopher);

long		ft_atoi(char *str);

#endif
