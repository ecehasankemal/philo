#include "philo.h"

int
	main(int ac, char *av[])
{
	t_env	env;

	if (!ft_parser(ac, av))
		return (ft_error("Error arguments"));
	if (!ft_init(&env, ac, av))
		return (1);
	ft_basis(&env);
	return (0);
}
