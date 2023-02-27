/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_large.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejarod <alejarod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 10:49:23 by alejarod          #+#    #+#             */
/*   Updated: 2023/02/19 12:13:37 by alejarod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// push items from A to B except the last 3. Push small indexes first, that
// will be kept at the bottom of B, the larger indexes on the top of B. But still unsorted
static void	ft_push_but_three(t_stack **head_a, t_stack **head_b)
{
	int	push_count;		// counter of how many I am pushing to stack B
	int	i;
	int	size;			// size of list A

	push_count = 0;
	i = 0;
	size = ft_list_size(*head_a);
	//printf("size is |%d|\n", size);
	// while ((size > 6) && (i < size) && (push_count < size / 2))
	while ((i < size) && (push_count < (size / 2)))
	{
		if ((*head_a)->index < (size / 2))	// push the lowest numbers to stack B
		{
			ft_pb(head_a, head_b);
			push_count++;
		}
		else if ((*head_a)->index > (size / 2))	// if the number is big, dont push it yet
		{
			ft_ra(head_a);		// rotate big number to the bottom of A and continue loop
		}
		i++;	// loop until i equals size
	}
	while ((size - push_count) > 3)	// push the rest that are pending (rotated in a but not pushd to B, except 3)
	{
		ft_pb(head_a, head_b);
		push_count++;
	}
}

// After B is empty, sort A by bringing the lowest position to the top
// if it is in the half bottom, rra, if it is in the top half, ra
static void	ft_final_sort_a(t_stack **head_a)
{
	int	min_index_pos;
	int	size;

	size = ft_list_size(*head_a);
	//printf("size of A after B was pushed: |%d|\n", size);
	min_index_pos = ft_min_index_pos(head_a);			// finds the position of the lowest number (where the lowest index is, is is in the pos 5, 10, 24??)
	if (min_index_pos < (size / 2))
	{
		while (min_index_pos > 0)	// move the smallest index to the top
		{
			ft_ra(head_a);
			min_index_pos--;
		}
	}
	else
	{
		while (min_index_pos < size)	// until it is not in the end
		{
			ft_rra(head_a);
			min_index_pos++;
		}
	}
}

// push all but 3 to B, sort A, calculate cost
void	ft_sort_large(t_stack **head_a, t_stack **head_b)
{
	//ft_print_list(head_a, head_b);
	ft_push_but_three(head_a, head_b);
	// push all but 3 to stack B
	ft_sort_three(head_a);
	while (*head_b)
	{
		ft_target_pos(head_a, head_b);
		ft_calc_cost(head_a, head_b);
		ft_exec_lowcost(head_a, head_b);
	}
	if (ft_lst_issorted(*head_a) == 0)
		ft_final_sort_a(head_a);
}
