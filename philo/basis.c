/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basis.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hece <hece@student.42kocaeli.com.tr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/16 19:16:49 by hece              #+#    #+#             */
/*   Updated: 2023/04/16 19:16:50 by hece             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static inline int
	ft_monitor(t_env *env)
{
	register int	index;

	index = 0;
	while (index < env->amount)
	{
		if (env->philos[index].must_eat != 0)
			return (1);
		index++;
	}
	return (0);
}

static inline void
	ft_cycle(t_env *env)
{
	register int	index;

	index = 0;
	while (ft_monitor(env))
	{
		if (index == env->amount)
			index = 0;
		pthread_mutex_lock(&env->message);
		if (ft_get_time() - env->start_time - env->philos[index].last_eat > \
			env->time_die)
		{
			printf("%ld\t%d died\n", \
				ft_get_time() - env->start_time, env->philos[index].number);
			pthread_mutex_unlock(&env->message);
			break ;
		}
		pthread_mutex_unlock(&env->message);
		index++;
	}
}

static inline void
	ft_end(t_env *env)
{
	register int	index;

	index = 0;
	while (index < env->amount)
	{
		pthread_mutex_destroy(&env->philos[index].fork);
		index++;
	}
	pthread_mutex_destroy(&env->message);
	if (env->philos)
		free(env->philos);
}

void
	ft_basis(t_env *env)
{
	register int	index;

	index = -1;
	if (ft_threads(env))
	{
		ft_cycle(env);
		while (++index < env->amount)
			pthread_detach(env->philos[index].t);
	}
	else
		printf("Couldn't create a thread for philosopher\n");
	ft_end(env);
}
