/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejarod <alejarod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 21:36:39 by alejarod          #+#    #+#             */
/*   Updated: 2023/02/24 23:13:41 by alejarod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../srcs/push_swap.h"

char	*ft_strndup(char *str, int len)
{
	char	*ptr;

	ptr = (char *)malloc(sizeof(char) * len + 1);
	if (!ptr)
		return (0);
	ptr[len--] = '\0';
	while (len >= 0)
	{
		ptr[len] = str[len];
		len--;
	}
	return (ptr);
}

int	ft_wordcount(char *str)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i])
	{
		if (ft_isspace(str[i]) == 0 && \
		(ft_isspace(str[i + 1]) == 1 || str[i + 1] == '\0'))
			count++;
		i++;
	}
	return (count);
}

char	**ft_split(char *str)
{
	char	**ptr;
	int		i;
	int		word;
	int		start;

	i = 0;
	word = 0;
	ptr = (char **)malloc(sizeof(char *) * (ft_wordcount(str) + 1));
	if (!ptr)
		return (0);
	while (str[i])
	{
		while (str[i] && ft_isspace(str[i]) == 1)
			i++;
		start = i;
		while (str[i] && ft_isspace(str[i]) == 0)
			i++;
		if (i > start)
		{
			ptr[word] = ft_strndup(str + start, i - start);
			word++;
		}
	}
	ptr[word] = 0;
	return (ptr);
}
