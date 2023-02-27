/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_argv.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejarod <alejarod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 14:27:45 by alejarod          #+#    #+#             */
/*   Updated: 2023/02/18 13:08:34 by alejarod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// check float or strange characters
int	ft_check_digits(char *str)
{
	int i;

	i = 0;
 	if (ft_isdigit(str[0]) == 0 && str[0] != '-' && str[0] != '+' && str[0] != ' ')	// only admit digits or signs in str[0]
	{
		//printf("Error in str[0]. Introduce a digit from 0 to 9 or + or - sign\n");
		return (1);
	}
	i++;
	while (str[i])
	{
		// check signs inside argument
		if (str[i] == '-' || str[i] == '+')
		{
			if (!(ft_isdigit(str[i+1]) == 1 && ft_isspace(str[i - 1]) == 1))	// sign only valid if it is preceded by space and followed by number
			{
				//printf("|%c|\n", str[i]);
				//printf("Error. Sign only allowed at the after a space or before a number.\n");
				return (1);
			}
		}
		// check if there are strange chars
		if (ft_isdigit(str[i]) == 0 && ft_isspace(str[i]) == 0 && !(str[i] == '-' || str[i] == '+' ))
		{
			//printf("|%c|\n", str[i]);
			//printf("Error. Invalid chars detected\n");
			return (1);
		}
		i++;
	}
	//printf("return (0) digit check OK\n");
	return (0);
}
// encontrar números duplicados.
int	ft_duplicates(char **split, int word)
{
	int	i;		// lock counter at first word
	int	j;		// loop the rest of the arguments

	i = 0;
	//printf("entered ft_duplicates\n");
	//printf("total words in split: |%d|\n", word);
 	while (i < word)
	{
		//printf("word |%d| is: |%s|\n", i, split[i]);
		i++;
	}
	// check duplicates
	i = 0;		// reset word counter to 0
	while (i < word)
	{
		j = 0;
		while (j < word)	//loop the array of splits
		{
			long a = ft_long_atoi(split[i]);	// is is locked
			long b = ft_long_atoi(split[j]);	// j is looped until the end
			if (i == j)	// skip if we are in the same position
			{
				j++;		// before returning to the top, increase j to avoid infinite loop
				continue;
			}
			if (a == b)		// check duplicate numbers
			{
				//printf("duplicates found |%ld| equal to |%ld|\n", a, b);
				//printf("duplicates found %d is equal to %d\n", ft_atoi(split[word]), ft_atoi(split[j]));
				//split = ft_free_split(split);
				//split = NULL;
				//printf("duplicates found %d is equal to %d\n", a, b);
				//printf("duplicates found %d is equal to %d\n", ft_atoi(split[word]), ft_atoi(split[j]));
				return (1);
			}
			j++;
		}
		i++;
	}
	//printf("return (0): no duplicates found\n");
	return (0);
}

int	ft_maxint(char **split, int word)
{
	int	i;
	long nbr;		// need a long to store all the chars

	//printf("entered check_max_int\n");
	i = 0;

	while (i < word)
	{
		nbr = ft_long_atoi(split[i]);
		if (nbr > INT_MAX || nbr < INT_MIN)
		{
			//printf("number |%ld| higher/lower than int\n", nbr);
			return (1);
		}
		i++;
	}
	//printf("ft_max_int return (0) OK\n");
	return (0);
}
int	ft_check_argv(char *temp_array, char **split, int word)
{

	// perform 3 checks: correct digits, no duplicates, no mumber > maxint or < minint
	if (ft_check_digits(temp_array) != 0 || ft_duplicates(split, word) != 0 || ft_maxint(split, word) != 0)
	{
		//printf("Error in digits, maxint or duplicates\n");
		return (1);
	}
	return (0);
}