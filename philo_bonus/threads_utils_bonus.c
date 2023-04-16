/* ************************************************************************** */
/*                                                                            */
/*   threads_utils_bonus.c                                                    */
/*                                                                            */
/*   By: Ataullin Shamil                                                      */
/*                                                                            */
/*   Created: 2022/06/01                                                      */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	ft_forks(t_philos *philos)
{
	sem_wait(philos->env->fork);
	sem_wait(philos->env->message);
	printf("%ld\t%d taken fork\n", \
		ft_get_time() - philos->env->start_time, philos->number);
	sem_post(philos->env->message);
	sem_wait(philos->env->fork);
	sem_wait(philos->env->message);
	printf("%ld\t%d taken fork\n", \
		ft_get_time() - philos->env->start_time, philos->number);
	sem_post(philos->env->message);
}

void	ft_eat(t_philos *philos)
{
	sem_wait(philos->env->message);
	printf("%ld\t%d is eating\n", \
		ft_get_time() - philos->env->start_time, philos->number);
	sem_post(philos->env->message);
	ft_usleep(ft_get_time(), philos->env->time_eat);
	sem_wait(philos->env->check);
	philos->time_to_die = ft_get_time();
	philos->eaten_meals++;
	sem_post(philos->env->check);
	sem_post(philos->env->fork);
	sem_post(philos->env->fork);
}

void	ft_sleep(t_philos *philos)
{
	sem_wait(philos->env->message);
	printf("%ld\t%d is sleeping\n", \
		ft_get_time() - philos->env->start_time, philos->number);
	sem_post(philos->env->message);
	ft_usleep(ft_get_time(), philos->env->time_sleep);
}

void	ft_think(t_philos *philos)
{
	sem_wait(philos->env->message);
	printf("%ld\t%d is thinking\n", \
		ft_get_time() - philos->env->start_time, philos->number);
	sem_post(philos->env->message);
}
