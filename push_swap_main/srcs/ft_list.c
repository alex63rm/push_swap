/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejarod <alejarod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 20:16:06 by alejarod          #+#    #+#             */
/*   Updated: 2023/02/24 22:51:50 by alejarod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*stack_new(int number)
{
	t_stack	*new;

	new = (t_stack *)malloc(sizeof(t_stack));
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
	if (!new)
		return ;
	if (!*head)
	{
		*head = new;
		return ;
	}
	while (cur->link != 0)
		cur = cur->link;
	cur->link = new;
	return ;
}

int	ft_list_size(t_stack *head)
{
	int		i;
	t_stack	*cur;

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
