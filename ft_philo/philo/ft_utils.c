/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysbai-jo <ysbai-jo@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 21:13:03 by ael-moha          #+#    #+#             */
/*   Updated: 2024/11/23 14:06:16 by ysbai-jo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_philo.h"

static int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

size_t	current_time_in_milliseconds(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return (((tv.tv_sec) * 1000) + ((tv.tv_usec) / 1000));
}

static int	ft_is_nbr(char *nbr)
{
	int	i;

	i = 0;
	while (nbr[i])
	{
		if (!ft_isdigit(nbr[i++]))
			return (0);
	}
	return (1);
}

static int	ft_check_max_zero(int ac, char **args)
{
	if (ac != 5 && ac != 6)
	{
		ft_perror('c');
		return (0);
	}
	if (ft_is_nbr(args[1]) && ft_atoi(args[1]) == 0)
	{
		ft_perror('z');
		return (0);
	}
	return (1);
}

int	is_valid(int ac, char **args)
{
	int	i;

	i = 1;
	if (!ft_check_max_zero(ac, args))
		return (0);
	while (i < ac)
	{
		if (!ft_is_nbr(args[i]))
		{
			ft_perror('p');
			return (0);
		}
		i++;
	}
	return (1);
}
