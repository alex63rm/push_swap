/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejarod <alejarod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 14:43:08 by alejarod          #+#    #+#             */
/*   Updated: 2023/05/01 19:52:23 by alejarod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

/* --------------------------C STANDARD LIBRARIES-----------------------------*/

# include<stdio.h>
# include<unistd.h>
# include<stdlib.h>
# include<limits.h>

/* --------------------------------PROTOTYPES---------------------------------*/

typedef struct s_stack
{
	int				number;
	int				index;
	int				pos;
	int				target_pos;
	int				cost_a;
	int				cost_b;
	struct s_stack	*link;
}	t_stack;

typedef struct s_utils
{
	char	**split;
	char	*temp_array;
}	t_utils;

/*-----------------------------------LIBFT------------------------------------*/

int		ft_isdigit(int c);
int		ft_isspace(int c);
int		ft_check_digits(char *str);
char	**ft_split(char *str);
void	ft_free_split(char **split);
int		ft_duplicates(char **str, int word);
int		ft_maxint(char **split, int word);
int		ft_isdigit(int c);
int		ft_atoi(char *str);
long	ft_long_atoi(char *str);
void	ft_putstr(char *str);
char	*ft_strjoin_endspace(char *s1, char const *s2);
int		ft_strlen(const char *s);
char	*ft_strdup(const char *s1);

/*-----------------------------------MAIN FT----------------------------------*/

char	*ft_create_temp_array(char **argv);
int		ft_check_argv(char *temp_array, char **split, int word);
t_stack	*ft_save_numbers(int ac, char **av);
void	ft_assign_index(t_stack *head_a, int ac);
void	ft_sort_three(t_stack **head);
void	ft_sort_large(t_stack **head_a, t_stack **head_b);
int		ft_min_index_pos(t_stack **head);
void	ft_target_pos(t_stack **head_a, t_stack **head_b);
void	ft_calc_cost(t_stack **head_a, t_stack **head_b);
void	ft_exec_lowcost(t_stack **head_a, t_stack **head_b);
void	ft_instruction(t_stack **a, t_stack **b, int cost_a, int cost_b);
void	ft_free_utils(t_utils *utils);
void	ft_exit_error(t_stack **head_a, t_stack **head_b);

/*---------------------------------LIST FT------------------------------------*/

int		ft_lst_issorted(t_stack *head);
t_stack	*stack_new(int number);
void	ft_lst_add_end(t_stack **head, t_stack *new);
int		ft_list_size(t_stack *head);
void	ft_free_list(t_stack **head);

/*--------------------------------INSTRUCTIONS--------------------------------*/

void	ft_pa(t_stack **head_a, t_stack **head_b);
void	ft_pb(t_stack **head_a, t_stack **head_b);
void	ft_sa(t_stack **head_a);
void	ft_sb(t_stack **head_b);
void	ft_ra(t_stack **head_a);
void	ft_rb(t_stack **head_b);
void	ft_rr(t_stack **head_a, t_stack **head_b);
void	ft_rrr(t_stack **head_a, t_stack **head_b);
void	ft_rra(t_stack **head_a);
void	ft_rrb(t_stack **head_b);

#endif