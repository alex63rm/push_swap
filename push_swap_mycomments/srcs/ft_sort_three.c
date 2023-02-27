/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_three.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejarod <alejarod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 22:22:53 by alejarod          #+#    #+#             */
/*   Updated: 2023/02/22 20:32:33 by alejarod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// find and return the highest index in the list
static int	ft_find_highest_index(t_stack *head_a)
{
	//printf("entered find highest index\n");
	int highest;
	t_stack *cur;

	cur = head_a;
	highest = 0;		// my index starts at 1, so 0 will be the smallest
	while (cur)
	{
		if (cur->index > highest)
			highest = cur->index;	// save the highest value found while looping in highest
		cur = cur->link;

	}
	//printf("highest is |%d|\n", highest);
	//printf("exit find-highest_index\n");
	return (highest);
}

// find max value, then perform actions depending on position of max
void	ft_sort_three(t_stack **head_a)
{
	int		highest_index;

	if (ft_lst_issorted(*head_a) == 1)
		return ;
	highest_index = ft_find_highest_index(*head_a);
	if ((*head_a)->index == highest_index)		// 30 20 10 or 30 10 20 if highest is in the first position
	{
		ft_ra(head_a);		// the new head gets updated, list becomes: 20 10 30 or 20 30 10
		//printf("cur->index is |%d| and cur->link->index is |%d|\n", cur->index, cur->link->index);
 		if ((*head_a)->index > (*head_a)->link->index)	// if 20 10 30, sa to convert: 10 20 30
			ft_sa(head_a);
	}
	else if ((*head_a)->link->index == highest_index)			// 10 30 20 or 20 30 10 if highest is in the middle position
	{
		ft_rra(head_a);		// list becomes 20 10 30 or 10 20 30
		if ((*head_a)->index > (*head_a)->link->index)	// if 20 10 30, sa to convert 10 20 30
			ft_sa(head_a);
	}
	else
		ft_sa(head_a);
}