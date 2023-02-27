/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejarod <alejarod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 21:39:43 by alejarod          #+#    #+#             */
/*   Updated: 2023/02/19 11:54:53 by alejarod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// top element is sent to bottom of the list
static void	ft_rotate(t_stack **head)
{
	t_stack	*cur;
	t_stack	*new_head;	// I will copy the head node

	cur = *head;
	new_head = cur->link;		// save position of the new head
	if (*head == NULL || (*head)->link == NULL)
		return ;
	while (cur->link)
		cur = cur->link;	// reach the last node
	(*head)->link = NULL;	//old head link set to 0
	cur->link = *head;	// points to the old head
	*head = new_head;		// update head with its new value
}

void	ft_ra(t_stack **head_a)
{
	ft_rotate(head_a);
	ft_putstr("ra\n");
}

void	ft_rb(t_stack **head_b)
{
	ft_rotate(head_b);
	ft_putstr("rb\n");
}

void	ft_rr(t_stack **head_a, t_stack **head_b)
{
	ft_rotate(head_a);
	ft_rotate(head_b);
	ft_putstr("rr\n");
}
