/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejarod <alejarod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 19:51:23 by alejarod          #+#    #+#             */
/*   Updated: 2023/02/22 22:00:28 by alejarod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_lst_issorted(t_stack *head)
{
	t_stack	*cur;

	cur = head;
	while (cur->link != NULL)
	{
		if (cur->number > cur->link->number)
			return (0);
		cur = cur->link;
	}
	return (1);
}

static void	ft_push_swap(t_stack **head_a, t_stack **head_b, int size)
{
	if (size < 2)
		return ;
	else if (size == 2 && ft_lst_issorted(*head_a) == 0)
		ft_sa(head_a);
	else if (size == 3 && ft_lst_issorted(*head_a) == 0)
		ft_sort_three(head_a);
	else if (ft_lst_issorted(*head_a) == 0)
		ft_sort_large(head_a, head_b);
}

int	main(int argc, char **argv)
{
	t_stack	*head_a;
	t_stack	*head_b;
	t_utils	utils;
	int		word;

	word = 0;
	if (argc < 2)
		return (0);
	utils.temp_array = ft_create_temp_array(argv);
	utils.split = ft_split(utils.temp_array);
	while (utils.split[word])
		word++;
	if (ft_check_argv(utils.temp_array, utils.split, word) == 1)
	{
		ft_free_utils(&utils);
		ft_exit_error(NULL, NULL);
	}
	head_b = NULL;
	head_a = ft_save_numbers(word, utils.split);
	ft_assign_index(head_a, word);
	ft_push_swap(&head_a, &head_b, word);
	ft_free_list(&head_a);
	ft_free_list(&head_b);
	ft_free_utils(&utils);
	return (0);
}
