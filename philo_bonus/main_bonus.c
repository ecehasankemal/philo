/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hece <hece@student.42kocaeli.com.tr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/16 19:20:04 by hece              #+#    #+#             */
/*   Updated: 2023/04/16 19:20:05 by hece             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void
	ft_end_program(t_env *env)
{
	register int	index;
	int				status;

	index = -1;
	while (++index < env->amount)
	{
		waitpid(-1, &status, 0);
		if (WEXITSTATUS(status) == 1)
		{
			index = -1;
			while (++index < env->amount)
				kill(env->philos[index].pid, SIGTERM);
			break ;
		}
	}
	sem_close(env->message);
	sem_close(env->check);
	sem_close(env->fork);
	sem_unlink("/print");
	sem_unlink("/check");
	sem_unlink("/forks");
	free(env->philos);
}

static inline void
	ft_basis(t_env *env)
{
	register int	index;

	index = -1;
	env->start_time = ft_get_time();
	while (++index < env->amount)
	{
		env->philos[index].time_to_die = env->start_time;
		env->philos[index].pid = fork();
		if (env->philos[index].pid == -1)
			exit(EXIT_FAILURE);
		if (env->philos[index].pid == 0)
			ft_threads(&env->philos[index]);
	}
}

int
	main(int ac, char *av[])
{
	t_env	env;

	if (!ft_parser(ac, av))
		return (0);
	ft_init(&env, ac, av);
	ft_basis(&env);
	ft_end_program(&env);
	return (0);
}
