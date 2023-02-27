/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_save_numbers.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejarod <alejarod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 20:25:22 by alejarod          #+#    #+#             */
/*   Updated: 2023/02/22 20:38:17 by alejarod         ###   ########.fr       */
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
		num = ft_atoi(split[i]);
		if (i == 0)
			head_a = stack_new(num);
		else
			ft_lst_add_end(&head_a, stack_new(num));
		i++;
	}
	return (head_a);
}

// assign an index according to the order of the number
void	ft_assign_index(t_stack *head_a, int size)
{
	t_stack	*cur;
	t_stack	*mark_highest_node;
	long	temp;

	cur = head_a;
	while (size > 0)
	{
		cur = head_a;
		temp = -2147483649;
		while (cur)
		{
			if (cur->number > temp && !(cur->index))
			{
				temp = cur->number;
				mark_highest_node = cur;
			}
			cur = cur->link;
		}
		size--;
		mark_highest_node->index = size;
	}
}
