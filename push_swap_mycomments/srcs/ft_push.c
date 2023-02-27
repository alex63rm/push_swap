/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejarod <alejarod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 20:43:39 by alejarod          #+#    #+#             */
/*   Updated: 2023/02/19 16:16:54 by alejarod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_push(t_stack **src, t_stack **dst)
{
	//printf("***!!!entered ft_push***!!!\n");
	t_stack	*cur;
	if (*src == NULL)
		return ;
	cur = *src;
	cur = (*src)->link;		// save the position of the next node of A to turn it to the head later
	(*src)->link = *dst;	// point link of head A to first node of B
	*dst = *src;			// update the head of dst
	*src = cur;				// update the head of src
}

void	ft_pa(t_stack **head_a, t_stack **head_b)
{
	ft_push(head_b, head_a);
	ft_putstr("pa\n");
}

void	ft_pb(t_stack **head_a, t_stack **head_b)
{
	ft_push(head_a, head_b);
	ft_putstr("pb\n");
}
