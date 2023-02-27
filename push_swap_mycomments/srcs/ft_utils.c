/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejarod <alejarod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 11:05:15 by alejarod          #+#    #+#             */
/*   Updated: 2023/02/22 20:17:38 by alejarod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_free_split(char **split)
{
	int	word;

	word = 0;
	if (split == NULL)	// avoids SIGSEV if split is NULL
		return ;
	while (split[word])
	{
		free(split[word]);
		word++;
	}
	free(split);	// free the first array of pointers
}

void	ft_free_list(t_stack **head)
{
	t_stack *cur;

	if (head == NULL || *head == NULL)	// check, else segfault by trying to access a NULL address
		return ;
	cur = *head;		// need double pointer to delete it in the save_numbers function
	while (cur->link)	// if I do a single pointer, it just gets deleted locally
	{
		cur = cur->link;	// advance cur
		free(*head);
		*head = cur;		// advance head (acts as previous) delete it
	}
	free(*head);		// delete the current (LAST) node, because I exited the loop at the last node
	*head = NULL;		// cur and prev are local, they get deleted at function exit
	//printf ("local *head after deletion is |%p|\n", *head);
	return ;
}

void	ft_exit_error(t_stack **head_a, t_stack **head_b)
{
	if (head_a == NULL || *head_a != NULL)
		ft_free_list(head_a);
	if (head_b == NULL || *head_b != NULL)
		ft_free_list(head_b);
	write(2, "Error\n", 6);
	exit (1);
}
