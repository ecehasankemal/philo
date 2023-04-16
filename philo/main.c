/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hece <hece@student.42kocaeli.com.tr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/16 19:16:54 by hece              #+#    #+#             */
/*   Updated: 2023/04/16 19:16:55 by hece             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
