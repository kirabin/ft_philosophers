#ifndef PHILO_ONE_H
# define PHILO_ONE_H

/*
**
**  time_to_die is set in milliseconds
**
**
*/

typedef struct s_input
{
	int	number_of_philosophers;
	int	number_of_forks;
	int	time_to_die;
	int	time_to_eat;
	int	time_to_sleep;
	int	number_of_times_each_philosopher_must_eat;
}	t_input;

typedef struct s_philosopher
{
	int	id;
	
}	t_philosopher;


#endif
