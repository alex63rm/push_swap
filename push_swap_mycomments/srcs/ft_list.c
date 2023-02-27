/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejarod <alejarod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 20:16:06 by alejarod          #+#    #+#             */
/*   Updated: 2023/02/19 16:48:08 by alejarod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*stack_new(int number)
{
	t_stack	*new;

	new = (t_stack *)malloc(sizeof(t_stack));	// allocate space for the new node
	if (!new)
		return (NULL);
	new->number = number;
	new->index = 0;
	new->pos = -1;
	new->target_pos = -1;
	new->cost_a = -1;
	new->cost_b = -1;
	new->link = NULL;
	return (new);
}

void	ft_lst_add_end(t_stack **head, t_stack *new)
{
	t_stack	*cur;

	cur = *head;
	if (!new)		// protection in case no space for new
		return ;
	if (!*head)		// just in case. Not necessary because there will always be a head
	{
		*head = new;
		return ;
	}
	while (cur->link != 0)
		cur = cur->link;	// traverse the list to the last node
	cur->link = new;	// link the last node to the new one
	return ;
}

int	ft_list_size(t_stack *head)
{
	int 	i;
	t_stack *cur;	// really not necessary because this stack is just a copy

	i = 0;
	cur = head;
	if (cur == NULL)
		return (0);
	while (cur)
	{
		cur = cur->link;
		i++;
	}
	return (i);
}

void	ft_print_list(t_stack **head_a, t_stack **head_b)
{
	int i = 0;
	t_stack	*cur_a;
	t_stack *cur_b;

	if (*head_a == NULL)
	{
		printf("A is NULL\n");
	}
	if (*head_b == NULL)
		printf("B is NULL\n");
	cur_a = *head_a;
	cur_b = *head_b;
	while (cur_a != NULL)
	{
		printf("A: data |%d| is |%d| and index is |%d|\n", i, cur_a->number, cur_a->index);
		cur_a = cur_a->link;
		i++;
	}
	while (cur_b != NULL)
	{
		printf("B: data |%d| is |%d| and index is |%d|\n", i, cur_b->number, cur_b->index);
		cur_b = cur_b->link;
		i++;
	}
}