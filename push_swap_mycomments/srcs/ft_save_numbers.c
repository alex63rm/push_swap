/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_save_numbers.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejarod <alejarod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 20:25:22 by alejarod          #+#    #+#             */
/*   Updated: 2023/02/19 16:50:47 by alejarod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// save the numbers into the list
t_stack	*ft_save_numbers(int word, char **split)
{
	t_stack		*head_a;
	int			i;
	int			num;

	head_a = NULL;
	num = 0;
	i = 0;
	while (i < word)
	{
		num = ft_atoi(split[i]);	// convert to number
		if (i == 0)
			head_a = stack_new(num);	// first position is the head
		else
			ft_lst_add_end(&head_a, stack_new(num));
		i++;
	}
	return (head_a);
}

// assign an index according to the order of the number
void	ft_assign_index(t_stack *head_a, int size)
{
	t_stack *cur;
	t_stack	*mark_highest_node;
	long	temp;

	cur = head_a;
	//printf("entered assign index\n");
	while (size > 0)		// loop backwards from size to 0
	{
		cur = head_a;
		temp = -2147483649;		// it starts one less than the minimum value possible (to avoid the special case of INT_MIN)
		while (cur)
		{
			if (cur->number > temp && !(cur->index))	// if a value is higher than temp, replace temp (first iteration will always enter)
			{						// (&& !(cur->index)) to skip the nodes that have been already assigned an index, otherwise I would be overwriting same numbers
				temp = cur->number;	// assign to temp the value of the higher number found
				mark_highest_node = cur;
			}
			cur = cur->link;
		}
		size--;
		mark_highest_node->index = size;
	}
}
