/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hece <hece@student.42kocaeli.com.tr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/16 19:20:11 by hece              #+#    #+#             */
/*   Updated: 2023/04/16 19:20:12 by hece             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

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
	while (1)
	{
		if (ac != 5 && ac != 6)
			break ;
		if (!ft_check_digits(av))
			break ;
		if (!ft_check_max(av))
			break ;
		return (1);
	}
	printf("Error argument\n");
	return (0);
}
