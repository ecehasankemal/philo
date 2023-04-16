#include "philo.h"

static inline int
	ft_clean(t_env *env, int size)
{
	register int	index;

	index = -1;
	if (size != 0)
		env->amount = size;
	while (++index < env->amount)
		pthread_mutex_destroy(&env->philos[index].fork);
	if (env->philos)
		free(env->philos);
	return (0);
}

static inline int
	ft_init_forks(t_env *env)
{
	register int	index;

	index = 0;
	while (index < env->amount)
		if (pthread_mutex_init(&env->philos[index++].fork, NULL) != 0)
			return (ft_clean(env, index));
	if (pthread_mutex_init(&env->message, NULL) != 0)
		return (ft_clean(env, 0));
	return (1);
}

static inline int
	ft_init_philos(t_env *env)
{
	register int	i;

	i = -1;
	env->philos = malloc(sizeof(t_philos) * env->amount);
	if (!env->philos)
		return (0);
	while (++i < env ->amount)
	{
		env->philos[i].number = i + 1;
		env->philos[i].env = env;
		if (i == env->amount - 1)
			env->philos[i].friends_fork = &env->philos[0].fork;
		else
			env->philos[i].friends_fork = &env->philos[i + 1].fork;
		env->philos->last_eat = 0;
		env->philos[i].must_eat = env->must_eat;
	}
	return (1);
}

// first parameters philosophers numbers = amount
// second parameters philo is eating last dead numbers
// 3.(.d) parameters philo is eating time
// 4.(.d) parameters philo is sleeping time
// 5.(.d) parameters philos is must eat numbers
// if 5. parameters not empty = fill 5th parameter with atoi 

int
	ft_init(t_env *env, int ac, char *av[])
{
	env->amount = ft_atoi(av[1]);
	env->time_die = ft_atoi(av[2]);
	env->time_eat = ft_atoi(av[3]);
	env->time_sleep = ft_atoi(av[4]);
	env->must_eat = -1;
	if (ac == 6)
		env->must_eat = ft_atoi(av[5]);
	if (!ft_init_philos(env))
	{
		printf("Malloc error\n");
		return (0);
	}
	if (!ft_init_forks(env))
	{
		printf("Mutex error\n");
		return (0);
	}
	return (1);
}
