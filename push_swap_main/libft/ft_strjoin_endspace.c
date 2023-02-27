/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_endspace.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejarod <alejarod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 21:26:22 by alejarod          #+#    #+#             */
/*   Updated: 2023/02/24 23:07:33 by alejarod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../srcs/push_swap.h"

char	*ft_strjoin_endspace(char *s1, char const *s2)
{
	int		i;
	int		j;
	char	*ptr;

	ptr = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2)) + 2);
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
	ptr[i + j] = 32;
	ptr[i + j + 1] = '\0';
	return (ptr);
}
