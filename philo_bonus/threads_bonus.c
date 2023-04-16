/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hece <hece@student.42kocaeli.com.tr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/16 19:20:39 by hece              #+#    #+#             */
/*   Updated: 2023/04/16 19:20:42 by hece             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void
	*check_dead(void *args)
{
	t_philos	*philos;

	philos = (t_philos *)args;
	while (!philos->env->dead && philos->eaten_meals \
	< philos->env->must_eat)
	{
		sem_wait(philos->env->check);
		if (ft_get_time() - philos->time_to_die > philos->env->time_die)
		{
			philos->env->dead = 1;
			sem_wait(philos->env->message);
			printf("%ld\t%d dead\n", \
			ft_get_time() - philos->env->start_time, philos->number);
			exit(1);
		}
		sem_post(philos->env->check);
	}
	return (NULL);
}

void
	ft_threads(t_philos *philos)
{
	if (pthread_create(&philos->t, NULL, check_dead, (void *)philos) != 0)
	{
		printf("Couldn't create a thread for philosopher\n");
		exit (0);
	}
	if (philos->number % 2 == 0)
		ft_usleep(ft_get_time(), philos->env->time_eat / 10);
	while (!(philos->env->dead))
	{
		ft_forks(philos);
		ft_eat(philos);
		if (philos->eaten_meals >= philos->env->must_eat)
			break ;
		ft_sleep(philos);
		ft_think(philos);
	}
	pthread_join(philos->t, NULL);
	exit(0);
}
