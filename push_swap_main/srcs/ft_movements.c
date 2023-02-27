/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_movements.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejarod <alejarod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 11:31:41 by alejarod          #+#    #+#             */
/*   Updated: 2023/02/22 20:59:17 by alejarod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* rev_rot both stacks until one of them is at the bottom (cost = -1), 
the rev_rot again to be at the top (cost = 0)
we are using a pointer to update the original value of the cost in the stack */
static void	ft_rev_rot_ab(t_stack **a, t_stack **b, int *cost_a, int *cost_b)
{
	while (*cost_a < 0 && *cost_b < 0)
	{
		(*cost_a)++;
		(*cost_b)++;
		ft_rrr(a, b);
	}
}

/* rot both stacks until one of the is at the top (cost = 0)
we are using a pointer to update the original value of the cost in the stack */
static void	ft_rot_ab(t_stack **a, t_stack **b, int *cost_a, int *cost_b)
{
	while (*cost_a > 0 && *cost_b > 0)
	{
		(*cost_a)--;
		(*cost_b)--;
		ft_rr(a, b);
	}
}

static void	ft_cost_rotate_a(t_stack **head_a, int *cost_a)
{
	while (*cost_a)
	{
		if (*cost_a > 0)
		{
			ft_ra(head_a);
			(*cost_a)--;
		}
		else if (*cost_a < 0)
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
		if (*cost_b > 0)
		{
			ft_rb(head_b);
			(*cost_b)--;
		}
		else if (*cost_b < 0)
		{
			ft_rrb(head_b);
			(*cost_b)++;
		}
	}
}

/* once we have the lowest cost movement, we rot or rev_rot the elements 
to the top before swaping. If both negative or positive, move them at
the same time to save movements. Then keep moving individually until
both are at the top. Finally push B to A. Update the value of the cost
as we rotate the stack, so we will send the address (&) of cost to 
get the value modified */
void	ft_instruction(t_stack **h_a, t_stack **h_b, int cost_a, int cost_b)
{
	if (cost_a < 0 && cost_b < 0)
		ft_rev_rot_ab(h_a, h_b, &cost_a, &cost_b);
	else if (cost_a > 0 && cost_b > 0)
		ft_rot_ab(h_a, h_b, &cost_a, &cost_b);
	ft_cost_rotate_a(h_a, &cost_a);
	ft_cost_rotate_b(h_b, &cost_b);
	ft_pa(h_a, h_b);
}
