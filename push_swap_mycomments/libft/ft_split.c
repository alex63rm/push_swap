/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejarod <alejarod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 21:36:39 by alejarod          #+#    #+#             */
/*   Updated: 2023/02/18 12:49:38 by alejarod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../srcs/push_swap.h"

char	*ft_strndup(char *str, int len)
{
	char	*ptr;

	ptr = (char *)malloc(sizeof(char) * len + 1);	// simple malloc and write a string
	if (!ptr)
		return (0);
	ptr[len--] = '\0';	// finish the string with nul
	while (len >= 0)	// careful with len >=, len - 1 etc
	{
		ptr[len] = str[len];
		len--;
	}
	return (ptr);
}

int	ft_wordcount(char *str)
{
	int i = 0;
	int count = 0;

	while (str[i])
	{
		if (ft_isspace(str[i]) == 0 && (ft_isspace(str[i + 1]) == 1 || str[i + 1] == '\0'))	// as usual, count at the end of the word or string
			count++;
		i++;
	}
	return (count);
}

char	**ft_split(char *str)
{
	char	**ptr;
	int 	i = 0;
	int		word = 0;
	int 	wordcount;
	int		start;
	int		end;

	wordcount = ft_wordcount(str);
	ptr = (char **)malloc(sizeof(char *) * (wordcount + 1));	// 1. count the words
	if (!ptr)
		return (0);
	while (str[i])									// 2. Loop all the words by moving the index. Similar to first_word and last_word
	{
		while (str[i] && ft_isspace(str[i]) == 1)	// loop spaces
			i++;
		start = i;									// save & fix the starting position
		while (str[i] && ft_isspace(str[i]) == 0)	// loop the index while there is a word, get the len of word
			i++;
		end = i;
		if (end > start)	// Exit condition. Also if (wordcount) and add wordcount--;
		{
			ptr[word] = ft_strndup(str + start, end - start);	// 3. Save the word with strndup.
			word++;
		}
		// i++ not necessary because I would skip one char
	}
	ptr[word] = 0;		// imac compiler gives error. We have to put ptr[word] = 0
	return (ptr);
}