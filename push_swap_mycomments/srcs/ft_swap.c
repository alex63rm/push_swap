/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejarod <alejarod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 20:43:39 by alejarod          #+#    #+#             */
/*   Updated: 2023/02/19 16:22:18 by alejarod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_node_swap(t_stack **head)
{
	t_stack *cur;
	t_stack	*temp;

	cur = *head;
	temp = *head;
	if (*head == NULL || (*head)->link == NULL) 	// if there is no list or list only has one element
		return ;									// for some reason, the pointer needs a ()
	temp = cur->link;
	cur = temp->link;
	(*head)->link = cur;
	temp->link = *head;
	*head = temp;
}

void	ft_sa(t_stack **head_a)
{
	ft_node_swap(head_a);
	ft_putstr("sa\n");
}

void	ft_sb(t_stack **head_b)
{
	ft_node_swap(head_b);
	ft_putstr("sb\n");
}