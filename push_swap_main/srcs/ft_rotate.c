/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejarod <alejarod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 21:39:43 by alejarod          #+#    #+#             */
/*   Updated: 2023/02/22 20:38:46 by alejarod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// top element is sent to bottom of the list
static void	ft_rotate(t_stack **head)
{
	t_stack	*cur;
	t_stack	*new_head;

	cur = *head;
	new_head = cur->link;
	if (*head == NULL || (*head)->link == NULL)
		return ;
	while (cur->link)
		cur = cur->link;
	(*head)->link = NULL;
	cur->link = *head;
	*head = new_head;
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
