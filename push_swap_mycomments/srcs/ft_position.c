/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   position.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejarod <alejarod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 19:55:37 by alejarod          #+#    #+#             */
/*   Updated: 2023/02/19 12:31:50 by alejarod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// loop a stack and assign the place/position of the node in the list
static void	ft_assign_pos(t_stack **head)
{
	t_stack *cur;		// just loop the list and assign a position to each node
	int i;

	i = 0;
	cur = *head;
	while (cur)
	{
		cur->pos = i;
		cur = cur->link;	// loop list
		i++;				// increase positions
	}
}

// find the position of the lowest number.
// just loop and substute IF we find a lowest index. return the position of that found lowest_index
int	ft_min_index_pos(t_stack **head_a)
{
	t_stack *cur_a;
	int	min_index;			// temp value to only replace if a smaller index is found
	int	min_index_pos;		// position of the lowest number in stack A

	cur_a = *head_a;
	min_index = INT_MAX;	// since we don't know the highest index in the stack, start with INT_MAX
	ft_assign_pos(head_a);	// check&test: sets the position of the head as the first (else it stays in the end)
	min_index_pos = INT_MAX;
	while (cur_a)
	{
		if (cur_a->index < min_index)
		{
			min_index_pos = cur_a->pos;	// save that position in the variable
			min_index = cur_a->index;			// update the minimun index value to check
		}
		cur_a = cur_a->link;
	}
	return (min_index_pos);
}


// loop stack A index: Check index of A to calculate where B should be placed
// 1. Check if index_b is lower than A. This means the item b could be push to stack A on the top
// if there is no lower number, make the target the lowest number found
// return that position as target_pos
static int	ft_locate_target(t_stack **head_a, int index_b, int target_index, int target_pos)
{
	//printf("entered locate target\n");
	t_stack	*cur_a;

	cur_a = *head_a;
	while (cur_a)
	{
		// 1.
		if (cur_a->index > index_b && cur_a->index < target_index)
		{
			target_index = cur_a->index;	// set the target index as a potential position, make it smaller every time
			target_pos = cur_a->pos;	// set the target position as a potential position, make it smaller every time
		}
		cur_a = cur_a->link;
	}
	if (target_index != INT_MAX)	// it found a highest index in A, we could potentially push B to A
	{
		//printf("target_pos: |%d| and target_index |%d|\n", target_pos, target_index);
		return (target_pos);
	}
	// if we did not find a bigger index in A than in B, assign the smallest index found as the target_pos
	cur_a = *head_a;	// reset the pointer to the head of A
	while (cur_a)	// it did not find a bigger index in A, so we will set target_pos at the smaller index
	{
		if (cur_a->index < target_index)
		{
			target_index = cur_a->index;	// set the smallest index found until the end
			target_pos = cur_a->pos;	// set also the position as the potential target position
		}
		cur_a = cur_a->link;
	}
	//printf("target_pos: |%d| and target_index |%d|\n", target_pos, target_index);
	return (target_pos);
}

// this function finds the position where an element in B should go in A
// the target position of an element in B is the position with index[a + 1]
// index [3] in stack B needs to be pushed to A when position of index [4] is at the top of stack A
void	ft_target_pos(t_stack **head_a, t_stack **head_b)
{
	t_stack	*cur_b;
	int	target_pos;

	cur_b = *head_b;
	target_pos = 0;
	ft_assign_pos(head_b);	// we need to set the position in B (where the items are currently placed)
	ft_assign_pos(head_a);	// we also need to set the positions in A (0, 1, 2, 3, 4.....)

	while (cur_b)
	{
		target_pos = ft_locate_target(head_a, cur_b->index, INT_MAX, target_pos);
		cur_b->target_pos = target_pos;		// update the target_pos
		cur_b = cur_b->link;
	}
	// printf("target pos is |%d|", target_pos);
}
