#include "philo.h"

static inline void
	ft_eat(t_philos *philo)
{
	pthread_mutex_lock(&philo->fork);
	pthread_mutex_lock(&philo->env->message);
	printf("%ld\t%d taken fork\n", \
		ft_get_time() - philo->env->start_time, philo->number);
	pthread_mutex_unlock(&philo->env->message);
	pthread_mutex_lock(philo->friends_fork);
	pthread_mutex_lock(&philo->env->message);
	printf("%ld\t%d taken fork\n", \
		ft_get_time() - philo->env->start_time, philo->number);
	pthread_mutex_unlock(&philo->env->message);
	pthread_mutex_lock(&philo->env->message);
	printf("%ld\t%d is eating\n", \
		ft_get_time() - philo->env->start_time, philo->number);
	philo->last_eat = ft_get_time() - philo->env->start_time;
	pthread_mutex_unlock(&philo->env->message);
	ft_usleep(ft_get_time(), philo->env->time_eat);
	pthread_mutex_unlock(&philo->fork);
	pthread_mutex_unlock(philo->friends_fork);
}

static inline void
	ft_sleep(t_philos *philo)
{
	pthread_mutex_lock(&philo->env->message);
	printf("%ld\t%d is sleeping\n", \
		ft_get_time() - philo->env->start_time, philo->number);
	pthread_mutex_unlock(&philo->env->message);
	ft_usleep(ft_get_time(), philo->env->time_sleep);
}

static inline void
	ft_think(t_philos *philo)
{
	pthread_mutex_lock(&philo->env->message);
	printf("%ld\t%d is thinking\n", \
		ft_get_time() - philo->env->start_time, philo->number);
	pthread_mutex_unlock(&philo->env->message);
}

static inline void
	*ft_live(void *pf)
{
	t_philos	*philo;

	philo = (t_philos *)pf;
	while (1)
	{
		if (philo->must_eat)
		{
			ft_eat(philo);
			if (philo->must_eat != -1)
				philo->must_eat--;
			if (philo->must_eat)
				ft_sleep(philo);
			if (philo->must_eat)
				ft_think(philo);
		}
	}
	return (0);
}

int
	ft_threads(t_env *env)
{
	register int	index;

	index = 0;
	env->start_time = ft_get_time();
	while (index < env->amount)
	{
		if (pthread_create(&env->philos[index].t, NULL, \
		ft_live, &env->philos[index]) != 0)
			return (0);
		index += 2;
	}
	index = 1;
	usleep(300);
	while (index < env->amount)
	{
		if (pthread_create(&env->philos[index].t, NULL, \
		ft_live, &env->philos[index]) != 0)
			return (0);
		index += 2;
	}
	return (1);
}
