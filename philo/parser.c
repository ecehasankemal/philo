#include "philo.h"

static inline int
	ft_check_digits(char *av[])
{
	register int	layer;
	register int	index;

	layer = 1;
	while (av[layer])
	{
		index = 0;
		while (av[layer][index])
		{
			if (!ft_isdigit(av[layer][index]))
				return (0);
			index++;
		}
		layer++;
	}
	return (1);
}

static inline int
	ft_check_max(char *av[])
{
	register int	index;

	index = 1;
	while (av[index])
	{
		if (ft_atoi(av[index]) <= 0)
			return (0);
		index++;
	}
	return (1);
}

int
	ft_parser(int ac, char *av[])
{
	if (ac != 5 && ac != 6)
		return (0);
	if (!ft_check_digits(av))
		return (0);
	if (!ft_check_max(av))
		return (0);
	return (1);
}
