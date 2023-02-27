/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejarod <alejarod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 11:05:15 by alejarod          #+#    #+#             */
/*   Updated: 2023/02/22 20:26:08 by alejarod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_free_split(char **split)
{
	int	word;

	word = 0;
	if (split == NULL)
		return ;
	while (split[word])
	{
		free(split[word]);
		word++;
	}
	free(split);
}

void	ft_free_list(t_stack **head)
{
	t_stack	*cur;

	if (head == NULL || *head == NULL)
		return ;
	cur = *head;
	while (cur->link)
	{
		cur = cur->link;
		free(*head);
		*head = cur;
	}
	free(*head);
	*head = NULL;
	return ;
}

void	ft_exit_error(t_stack **head_a, t_stack **head_b)
{
	if (head_a == NULL || *head_a != NULL)
		ft_free_list(head_a);
	if (head_b == NULL || *head_b != NULL)
		ft_free_list(head_b);
	write(2, "Error\n", 6);
	exit(1);
}

char	*ft_create_temp_array(char **argv)
{
	int		i;
	char	*temp_array;

	i = 1;
	temp_array = NULL;
	while (argv[i])
	{
		temp_array = ft_strjoin_endspace(temp_array, argv[i]);
		i++;
	}
	return (temp_array);
}

void	ft_free_utils(t_utils *utils)
{
	ft_free_split(utils->split);
	utils->split = NULL;
	free(utils->temp_array);
	utils->temp_array = NULL;
}
