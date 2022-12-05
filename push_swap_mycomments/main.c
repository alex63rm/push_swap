/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejarod <alejarod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 19:51:23 by alejarod          #+#    #+#             */
/*   Updated: 2022/12/05 17:57:49 by alejarod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>



void	ft_check_parameters(char *str)
{
	unsigned int i;


	i = 0;	
	while (str[i])
	{
		if (str[i] == '\"') // if we find "" we have to scroll through this string
			// ft_separate_arg (like split)
					// si hay algo que no es número, salvo espacios o más de un signo
			printf("there is \", ft_stplit\n");
	i++;
	}
			// check if there are just numbers, signs 
		//ft_atoi()
		printf("ft_atoi\n");
	printf("argument is: %s\n", str);
	
	// error if duplicates

	// error if n > max_int or lower than min_int
	
	// error if not an int

	
}





int	main(int argc, char **argv)
{
	int	i;
	
	i = 1;
	// if just ./a.out or just one argument, return nothing
	if (argc > 2)
	{
		while (i < argc)
		{
			ft_check_parameters(argv[i]);
			i++;
		}
		// ft_save_ints;
		/* 		Debes escribir un programa llamado push_swap que recibirá como argumento el
		stack a con el formato de una lista de enteros. El primer argumento debe ser el que
		esté encima del stack (cuidado con el orden). */
		
	}
	return (0);
}