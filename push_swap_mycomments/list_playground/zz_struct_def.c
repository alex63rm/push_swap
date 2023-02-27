/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zz_struct_def.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejarod <alejarod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 21:32:14 by alejarod          #+#    #+#             */
/*   Updated: 2023/01/28 13:03:28 by alejarod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// one way: DEFINE WITH ALIAS

typedef struct s_stack		// DECLARE stack is the structure tag to remember the fields inside
{								// I created a new data type of type "list_stack" with an alias of "stack"
	int	num;
	int index;
	struct s_stack *next;	// I don't have an alias yet, so I have to still call it "struct s_list"
} t_stack;		// this is my alias (to avoid writing struct t_stack all the time)
				// after, I can just write "stack stack_a" instead of "struct t_stack stack_a"

t_stack *stack_a;		// Define the structures with the alias
t_stack *stack_b;
// Now that I created my list, I need to create a node and link it to my list

// peek o head

typedef struct s_peek			// head or peek. It is the first node of the list
{
	int len;
	struct t_stack *head;
} t_peek;

t_peek *head;


//another way, without alias

struct s_stack
{
	int num;
	int index;
	struct s_stack *next;
};

struct s_stack *stack_a;
struct s_stack *stack_b;

// final way, without alias and defining at the same time

struct s_stack
{
	int num;
	int index;
	struct s_stack *next;
} stack_a, stack_b;

