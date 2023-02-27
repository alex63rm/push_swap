/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cost.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejarod <alejarod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 19:16:13 by alejarod          #+#    #+#             */
/*   Updated: 2023/02/24 22:54:02 by alejarod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_absolute(int nbr)
{
	if (nbr < 0)
		nbr = nbr * -1;
	return (nbr);
}

/* calculate the cost of moving an element from B to its correct position in A
cost_b is the cost of moving an element from B to the top of stack B
(to be able to push it). cost_a same for A
if element is in the bottom half, cost will be negative 
(to check if it is better to reverse rotate to move it to the top) */
void	ft_calc_cost(t_stack **head_a, t_stack **head_b)
{
	t_stack	*cur_a;
	t_stack	*cur_b;
	int		size_a;
	int		size_b;

	cur_a = *head_a;
	cur_b = *head_b;
	size_a = ft_list_size(cur_a);
	size_b = ft_list_size(cur_b);
	while (cur_b)
	{
		cur_b->cost_b = cur_b->pos;
		if (cur_b->pos > size_b / 2)
			cur_b->cost_b = (size_b - cur_b->pos) * -1;
		cur_b->cost_a = cur_b->target_pos;
		if (cur_b->target_pos > size_a / 2)
			cur_b->cost_a = (size_a - cur_b->target_pos) * -1;
		cur_b = cur_b->link;
	}
}

// find element with the lowest cost in B (including cost of rotating A to top)
void	ft_exec_lowcost(t_stack **head_a, t_stack **head_b)
{
	t_stack	*cur_b;
	int		cost_a;
	int		cost_b;
	int		lowest;
	int		total_cost;

	cur_b = *head_b;
	lowest = INT_MAX;
	while (cur_b)
	{
		total_cost = ft_absolute(cur_b->cost_b) + ft_absolute(cur_b->cost_a);
		if (total_cost < ft_absolute(lowest))
		{
			lowest = total_cost;
			cost_b = cur_b->cost_b;
			cost_a = cur_b->cost_a;
		}
		cur_b = cur_b->link;
	}
	ft_instruction(head_a, head_b, cost_a, cost_b);
}
