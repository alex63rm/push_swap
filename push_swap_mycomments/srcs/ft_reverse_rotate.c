/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reverse_rotate.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejarod <alejarod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 21:26:22 by alejarod          #+#    #+#             */
/*   Updated: 2023/02/19 16:22:18 by alejarod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_rev_rotate(t_stack **head)
{
	t_stack	*cur;
	t_stack	*prev;

	if (*head == NULL || (*head)->link == NULL)
		return ;
	cur = *head;
	prev = cur;

	while (cur->link)	// stop at the last node
	{
		prev = cur;
		cur = cur->link;
	}	// we reached the last node with cur and 1 node before with prev
	cur->link = *head;		// link last to head
	prev->link = NULL;
	*head = cur;			// new head value
}

void	ft_rra(t_stack **head_a)
{
	ft_rev_rotate(head_a);
	ft_putstr("rra\n");
}

void	ft_rrb(t_stack **head_b)
{
	ft_rev_rotate(head_b);
	ft_putstr("rrb\n");
}

void	ft_rrr(t_stack **head_a, t_stack **head_b)
{
	ft_rev_rotate(head_a);
	ft_rev_rotate(head_b);
	ft_putstr("rrr\n");
}
