/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_movements.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejarod <alejarod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 11:31:41 by alejarod          #+#    #+#             */
/*   Updated: 2023/02/19 16:44:36 by alejarod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// rev_rot both stacks until one of them is at the bottom (cost = -1), the rev_rot again to be at the top (cost = 0)
// we are using a pointer to update the original value of the cost in the stack
static void	ft_rev_rot_ab(t_stack **head_a, t_stack **head_b, int *cost_a, int *cost_b)
{
	while (*cost_a < 0 && *cost_b < 0)
	{
		(*cost_a)++;
		(*cost_b)++;
		ft_rrr(head_a, head_b);
	}
}

// rot both stacks until one of the is at the top (cost = 0)
// we are using a pointer to update the original value of the cost in the stack
static void	ft_rot_ab(t_stack **head_a, t_stack **head_b, int *cost_a, int *cost_b)
{
	while (*cost_a > 0 && *cost_b > 0)
	{
		(*cost_a)--;
		(*cost_b)--;
		ft_rr(head_a, head_b);
	}
}

static void	ft_cost_rotate_a(t_stack **head_a, int *cost_a)
{
	while (*cost_a)
	{
		if (*cost_a > 0)		// if we are in the top half, move it up
		{
			ft_ra(head_a);
			(*cost_a)--;
		}
		else if (*cost_a < 0)	// else, move it down
		{
			ft_rra(head_a);
			(*cost_a)++;
		}
	}
}

static void	ft_cost_rotate_b(t_stack **head_b, int *cost_b)
{
	while (*cost_b)
	{
		if (*cost_b > 0)		// if we are in the top half, move it up
		{
			ft_rb(head_b);
			(*cost_b)--;
		}
		else if (*cost_b < 0)	// else, move it down
		{
			ft_rrb(head_b);
			(*cost_b)++;
		}
	}
}

// once we have the lowest cost movement, we rot or rev_rot the elements to the top before swaping
// if both negative or positive, move them at the same time to save movements
// then keep moving individually until both are at the top
// finally push B to A
// we are going to update the value of the cost as we rotate the stack, so we will send the address (&) of cost to get the value modified
void	ft_instruction(t_stack **head_a, t_stack **head_b, int cost_a, int cost_b)
{
	if (cost_a < 0 && cost_b < 0)		// if both negative, means both numbers are in the bot half, rev_rotate both at the same time to save movements until one reaches the top (cost = 0)
		ft_rev_rot_ab(head_a, head_b, &cost_a, &cost_b);
	else if (cost_a > 0 && cost_b > 0)						// if both positive, means both numbers are in the top half, rev_rotate both at the same time to save movements until one reaches the top (cost = 0)
		ft_rot_ab(head_a, head_b, &cost_a, &cost_b);
	// optimize with: cost_b < 0 ? rev_rot_b : rot_b
	// and same with a
	ft_cost_rotate_a(head_a, &cost_a);
	ft_cost_rotate_b(head_b, &cost_b);
	ft_pa(head_a, head_b);
}
