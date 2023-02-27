/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_three.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejarod <alejarod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 22:22:53 by alejarod          #+#    #+#             */
/*   Updated: 2023/02/22 20:32:21 by alejarod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// find and return the highest index in the list
static int	ft_find_highest_index(t_stack *head_a)
{
	int		highest;
	t_stack	*cur;

	cur = head_a;
	highest = 0;
	while (cur)
	{
		if (cur->index > highest)
			highest = cur->index;
		cur = cur->link;
	}
	return (highest);
}

// find max value, then perform actions depending on position of max
void	ft_sort_three(t_stack **head_a)
{
	int		highest_index;

	if (ft_lst_issorted(*head_a) == 1)
		return ;
	highest_index = ft_find_highest_index(*head_a);
	if ((*head_a)->index == highest_index)
	{
		ft_ra(head_a);
		if ((*head_a)->index > (*head_a)->link->index)
			ft_sa(head_a);
	}
	else if ((*head_a)->link->index == highest_index)
	{
		ft_rra(head_a);
		if ((*head_a)->index > (*head_a)->link->index)
			ft_sa(head_a);
	}
	else
		ft_sa(head_a);
}
