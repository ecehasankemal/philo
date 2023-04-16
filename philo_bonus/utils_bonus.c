/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hece <hece@student.42kocaeli.com.tr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/16 19:18:25 by hece              #+#    #+#             */
/*   Updated: 2023/04/16 19:19:21 by hece             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

int
	ft_error(char *str)
{
	printf("%s\n", str);
	return (1);
}

int
	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	else
		return (0);
}

int
	ft_atoi(const char *str)
{
	register int		iter;
	register int		dop;
	register long int	result;

	iter = 0;
	dop = 1;
	result = 0;
	while ((str[iter] >= '\t' && str[iter] <= '\r') || str[iter] == ' ')
		iter++;
	if (str[iter] == '+' || str[iter] == '-')
	{
		if (str[iter] == '-')
			dop *= -1;
		iter++;
	}
	while (str[iter] >= '0' && str[iter] <= '9' && str[iter] != '\0')
	{
		result = ((str[iter] - '0') + (result * 10));
		if (result * dop <= -2147483649)
			return (0);
		else if (result * dop >= 2147483648)
			return (-1);
		iter++;
	}
	return (result * dop);
}

void
	ft_usleep(time_t now, int time)
{
	while (1)
	{
		if ((ft_get_time() - now) >= time)
			break ;
		usleep(100);
	}
}

time_t
	ft_get_time(void)
{
	struct timeval	start_time;

	gettimeofday(&start_time, NULL);
	return (start_time.tv_sec * 1000L + start_time.tv_usec / 1000L);
}
