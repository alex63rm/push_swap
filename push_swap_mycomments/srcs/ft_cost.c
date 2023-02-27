/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cost.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejarod <alejarod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 19:16:13 by alejarod          #+#    #+#             */
/*   Updated: 2023/02/19 16:21:15 by alejarod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_absolute(int nbr)
{
	if (nbr < 0)
		nbr = nbr * -1;
	return (nbr);
}

// calculate the cost of moving an element from stack B to its correct position in A
// cost_b is the cost of moving an element from B to the top of stack B (to be able to push it)
// cost_a same for A
// if element is in the bottom half, cost will be negative (to check if it is better to reverse rotate to move it to the top)
void	ft_calc_cost(t_stack **head_a, t_stack **head_b)
{
	t_stack *cur_a;
	t_stack	*cur_b;
	int	size_a;
	int	size_b;

	cur_a = *head_a;
	cur_b = *head_b;
	size_a = ft_list_size(cur_a);
	size_b = ft_list_size(cur_b);
	//printf("size of A is |%d| and size of B is |%d|\n", size_a, size_b);
	while (cur_b)
	{
		cur_b->cost_b = cur_b->pos;	// cost to move to top, for PA
		if (cur_b->pos > size_b / 2)
			cur_b->cost_b = (size_b - cur_b->pos) * -1;	// cost to bot, for RRB
		cur_b->cost_a = cur_b->target_pos;	// where it needs to go in A is the cost to rotate A to the top
		if (cur_b->target_pos > size_a / 2)	// if the target is in the low part, better to RRA
			cur_b->cost_a = (size_a - cur_b->target_pos) * -1;
		cur_b = cur_b->link;	// i++
	}
}

// find element with the lowest cost in B (including cost of rotating A to top)
void	ft_exec_lowcost(t_stack **head_a, t_stack **head_b)
{
	t_stack *cur_b;
	int	cost_a;
	int	cost_b;
	int	lowest;
	int	total_cost;	// cost in moves of (rev)rotating A and (rev)rotating B

	cur_b = *head_b;
	lowest = INT_MAX;
	while (cur_b)
	{
		total_cost = ft_absolute(cur_b->cost_b) + ft_absolute(cur_b->cost_a);
		if (total_cost < ft_absolute(lowest))	// if we find a lowest cost, update the value
		{
			lowest = total_cost;		// update value for the next iteration
			cost_b = cur_b->cost_b;		// extract & save the cost of B to send it to the next function
			cost_a = cur_b->cost_a;
		}
		cur_b = cur_b->link;
	}
	ft_instruction(head_a, head_b, cost_a, cost_b);
}
