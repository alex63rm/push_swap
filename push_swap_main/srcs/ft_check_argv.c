/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_argv.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejarod <alejarod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 14:27:45 by alejarod          #+#    #+#             */
/*   Updated: 2023/05/04 23:17:28 by alejarod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// check float or strange characters
int	ft_check_digits(char *str)
{
	int	i;

	i = 0;
	if (ft_isalpha(str[0]))
		return (1);
	if (str[0] == '-' || str[0] == '+')
	{
		if (!ft_isdigit(str[i + 1]))
			return (1);
	}
	i++;
	while (str[i])
	{
		if (str[i] == '-' || str[i] == '+')
		{
			if (!(ft_isdigit(str[i + 1]) == 1 && ft_isspace(str[i - 1]) == 1))
				return (1);
		}
		if (ft_isdigit(str[i]) == 0 && \
		ft_isspace(str[i]) == 0 && !(str[i] == '-' || str[i] == '+' ))
			return (1);
		i++;
	}
	return (0);
}

int	ft_duplicates(char **split, int word)
{
	int		i;
	int		j;
	long	a;
	long	b;

	i = 0;
	while (i < word)
	{
		j = 0;
		while (j < word)
		{
			a = ft_long_atoi(split[i]);
			b = ft_long_atoi(split[j]);
			if (i == j)
			{
				j++;
				continue ;
			}
			if (a == b)
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	ft_maxint(char **split, int word)
{
	int		i;
	long	nbr;

	i = 0;
	while (i < word)
	{
		nbr = ft_long_atoi(split[i]);
		if (nbr > INT_MAX || nbr < INT_MIN)
			return (1);
		i++;
	}
	return (0);
}

int	ft_check_argv(char *temp_array, char **split, int word)
{
	if (ft_check_digits(temp_array) != 0 || ft_duplicates(split, word) != 0 \
	|| ft_maxint(split, word) != 0)
		return (1);
	return (0);
}
