/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_endspace.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejarod <alejarod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 21:26:22 by alejarod          #+#    #+#             */
/*   Updated: 2023/02/15 20:44:18 by alejarod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../srcs/push_swap.h"

char	*ft_strjoin_endspace(char *s1, char const *s2)
{
	int	n;
	int	i;
	int	j;
	char	*ptr;

	n = ft_strlen(s1) + ft_strlen(s2);
	ptr = (char *)malloc(sizeof(char) * n + 2);		// one additional space for a blank space ' ' (int 32)
	if (!ptr)
		return (0);
	i = 0;
	if (s1)
	{
		while (s1[i])
		{
			ptr[i] = s1[i];
			i++;
		}
	}
	j = 0;
	while (s2[j])
	{
		ptr[i + j] = s2[j];
		j++;
	}
	ptr[i + j] = 32;		// one space to separate the strings in temp_array
	ptr[i + j + 1] = '\0';
	if (s1)
		free(s1);
	return (ptr);
}