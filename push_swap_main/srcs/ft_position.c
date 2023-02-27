/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_position.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejarod <alejarod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 19:55:37 by alejarod          #+#    #+#             */
/*   Updated: 2023/02/22 20:53:10 by alejarod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// loop a stack and assign the place/position of the node in the list
static void	ft_assign_pos(t_stack **head)
{
	t_stack	*cur;
	int		i;

	i = 0;
	cur = *head;
	while (cur)
	{
		cur->pos = i;
		cur = cur->link;
		i++;
	}
}

// find the position of the lowest number. Loop and substute if we find a lowest
// index. return the position of that found lowest_index
int	ft_min_index_pos(t_stack **head_a)
{
	t_stack	*cur_a;
	int		min_index;
	int		min_index_pos;

	cur_a = *head_a;
	min_index = INT_MAX;
	ft_assign_pos(head_a);
	min_index_pos = INT_MAX;
	while (cur_a)
	{
		if (cur_a->index < min_index)
		{
			min_index_pos = cur_a->pos;
			min_index = cur_a->index;
		}
		cur_a = cur_a->link;
	}
	return (min_index_pos);
}

// loop stack A index: Check index of A to calculate where B should be placed
// 1. Check if index_b is lower than A. This means the item b could be push to 
// stack A on the top
// if there is no lower number, make the target the lowest number found
// return that position as target_pos
static int	ft_locate_target(t_stack **head_a, int index_b, \
int target_index, int target_pos)
{
	t_stack	*cur_a;

	cur_a = *head_a;
	while (cur_a)
	{
		if (cur_a->index > index_b && cur_a->index < target_index)
		{
			target_index = cur_a->index;
			target_pos = cur_a->pos;
		}
		cur_a = cur_a->link;
	}
	if (target_index != INT_MAX)
		return (target_pos);
	cur_a = *head_a;
	while (cur_a)
	{
		if (cur_a->index < target_index)
		{
			target_index = cur_a->index;
			target_pos = cur_a->pos;
		}
		cur_a = cur_a->link;
	}
	return (target_pos);
}

// this function finds the position where an element in B should go in A
// the target position of an element in B is the position with index[a + 1]
// index [3] in stack B needs to be pushed to A when position of index [4] 
// is at the top of stack A
void	ft_target_pos(t_stack **head_a, t_stack **head_b)
{
	t_stack	*cur_b;
	int		target_pos;

	cur_b = *head_b;
	target_pos = 0;
	ft_assign_pos(head_b);
	ft_assign_pos(head_a);
	while (cur_b)
	{
		target_pos = ft_locate_target(head_a, cur_b->index, \
		INT_MAX, target_pos);
		cur_b->target_pos = target_pos;
		cur_b = cur_b->link;
	}
}
