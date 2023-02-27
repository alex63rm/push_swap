/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zz_playground.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejarod <alejarod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 20:03:28 by alejarod          #+#    #+#             */
/*   Updated: 2023/01/23 21:19:42 by alejarod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// creating a list

#include<stdio.h>

// Define the structure

typedef struct s_node
{
	int num;
	struct s_node *next;		// self reference pointer that we will equal to the next node
} t_node;					// this is an alias to avoid writing "struct s_node" every time

// Create a pointer that will point to the m,emory address in the heap
// note that it cannot be placed globally, so we need to create a function or place it in main

t_node	*ft_lstnew(void)
{
	t_node	*head;
	t_node	*first;	// need to create another name, else we lose the head
	t_node	*second;

	head = (t_node *)malloc(sizeof(t_node));
	if (head == NULL);
		return (0);
	head->num = 98;
	head->next = first;	// now link it with the next malloc address (both are of type t_node so they can be equaled)

	first = (t_node *)malloc(sizeof(t_node));
	if (first == NULL);
		return (0);
	first->num = 56;
	first->next = second;

	second = (t_node *)malloc(sizeof(t_node));	// we could keep adding like this, but it involves creating a pointer for every node.
	if (second == NULL);						// what if there are 20 nodes? There is another way
		return (0);
	second->num = 42;
	second->next = NULL;

	/* Another way of creating the second node is moving the "first" / "current" pointer instead of creating a different pointer for each node

	first = (t_node *)malloc(sizeof(t_node));	// now this node has been created in a different address (the previous one was busy)
	if (first == NULL)
		return (0);
	first->num = 42;
	first->next = NULL;
	head->next->next = first; // this is the important thing, to fill inside the second node the address of the third node,
	to avoid losing the address of the third node before moving the pointer first to another node it before making a new node
	*/

	return (head);	// return the head, which is the important one
}

int	count_of_nodes(t_node *head)
{
	int count = 0;	// my counter
	if (head == NULL)
		return (0);		// printf, the list is empty

	t_node *ptr;	// create a temporary pointer to avoid losing the head address (pointers are passed by reference, it affects the whole program)
	ptr = head;		// equal it to the address of the first node

	while (ptr != NULL)		// while it points to an address or node that has been created with malloc
	{
		count++;
		ptr = ptr->next;	// both are of type struct s_node *, so the addresses can be equaled.
	}

	return (count);

}

t_node	*add_at_end(t_node *head, int data)
{
	t_node *ptr;	// the pointer we will use to traverse the list
	t_node *new;	// the new node

	ptr = head;		// as usual, point the ptr to the head

	new = (t_node *)malloc(sizeof(t_node));		// allocate a memory address for the new node in the heap
	if (!new)
		return (0);
	new->num = data;	// receive the int parameter and insert it in the new node
	new->next = NULL;	// the new node is the last one, at the end

	// PART OF CODE:
	while (ptr->next != NULL)	// Step 1. Loop until the final node
	{
		ptr = ptr->next;		// to insert at the end, first we need to reach the last node
	}
	ptr->next = new;			// Step 2. Now that we are in the last node, we replace the NULL in ptr->next with the address of the new node (new)

	return (new);				// optional, we can return the updated pointer
}

// version 1.0. We need to return the head, because it is being received as a copy. We need to return the new value of head to main
t_node	*add_beg_1(t_node *head, int data)
{
	t_node	*new;
	t_node	*ptr;	// my current pointer that I will move

	ptr = head;		// equal the pointer to head

	new = (t_node *)malloc(sizeof(t_node));
	if (!new)
		return (0);
	new->num = data;
	new->next = NULL;	// new node as usual

	// CODE:
	new->next = head;	// Step 1. link the new node with the head. New always first to avoid losing the position
	head = new;			// Step 2. update the value of the head

	return (head);

}
// version 2.0. We receive a pointer to pointer, meaning we receive the address of head in main and it will be updated over there without return
void	add_beg_2(t_node **head, int data)
{
	t_node	*new;
	t_node	*ptr;

	new = (t_node *)malloc(sizeof(t_node));
	if (!new)
		return (0);
	new->num = data;
	new->next = NULL;

	new->next = *head;	// we are working with the address of head, add a pointer ??. New first to avoid losing the position
	*head = new;		// same as before but with a pointer
	// no need to return

}

void	add_at_pos(t_node *head, int data, int position)
{
	t_node *new;
	t_node *ptr;
	int i;

	ptr = head;

	new = (t_node *)malloc(sizeof(t_node));		// create new node as usual
	if (!new)
		return (0);
	new->num = data;
	new->next = NULL;

	i = 0;
	while (i < position)		// loop to reach the position before the insertion
	{
		ptr = ptr->next;
		i++;
	}
	new->next = ptr->next;		// Link new to next node first, else we lose the position
	ptr->next = new;			// redirect old node to new node
	return ;

}

t_node	*del_at_beg(t_node *head)
{
	t_node *tmp;

	if (head == NULL)	// first check that the list is not empty!!
		return (0);		// the list is already empty

	tmp = head;			// save the address of old head in temp to be able to delete it (like ft_swap)
	head = head->next;	// move the head one position // same as: head = head->next;
	free(tmp);			// delete the first node (free the malloc)
	return (head);		// return the updated head

}
// method 1 with 2 pointers
void	del_at_end(t_node *head)
{
	if (head == NULL)
	 	return (0);			// special case 1. the list is already empty
	else if (head->next == NULL)		// special case 2. there is only one node
	{
		free(head);			// delete the node and set that address to NULL.
		head = NULL;
	}
	else
	{
		t_node *temp;		// as usual to traverse
		t_node *temp2;		// use it to mark one position before the end
		while (temp->next != NULL)	// if there is another node after the current one
		{
			temp2 = temp;		// set temp2 to the current node
			temp = temp->next;	// move temp to the next node and check again
		}						// when we exit the loop, temp will be at the last node, and temp2 will be 1 node behind
		temp2->next = NULL;		// point that node to NULL
		free(temp);				// as usual, delete the node and the address
		temp = NULL;
		// return (head);		// optional, because the head is the same
	}
}

// method 2 with 1 pointer
t_node	*del_at_end2(t_node *head)
{
	if (head == NULL)
		return (0);
	else if (head->next == NULL)
	{
		free(head);
		head = NULL;
	}
	else
	{
		t_node *temp;
		while (temp->next->next != NULL)	// check if the next one to the current position is NULL
		{
			temp = temp->next;
		}
		free(temp->next);	// order is important. First free the last node
		temp->next = NULL;	// now make the link NULL to end the list
	}
	return (head);
}

// with head passed as value (not sure if 100% correct)
t_node	*del_at_pos(t_node *head, int position)
{
	int i = 0;				// just a counter
	t_node	*current;
	t_node	*previous;

	current = head;
	previous = head;

	if (head == NULL)
		return (0);			// if list is empty, return

	else if (position == 1)		// this is like del_at_beg (the head changes and we need to return it)
	{
		head = current->next;	// advance the head one position // same as: head = head->next
		free(current);
		current = NULL;
	}
	else
	{
		while (i < position)
		{
			previous = current;			// start equaling both pointers
			current = current->next;	// advance current (current will be one ahead when exiting the loop)
			i++;
		}
		previous->next = current->next;	// at loop exit, the current node is skipped. Previous is linked to the next node.
		free(current);					// delete the node
		current = NULL;					// point to null
	}
	return (head);
}

// with head passed as address (same but with *head and no need to return head)
t_node	*del_at_pos(t_node **head, int position)
{
	int i = 0;
	t_node	*current;
	t_node	*previous;

	current = *head;		// We received **head, so we don't know the content of head (just is address). So we access the content of head with the pointer *head
	previous = *head;

	if (*head == NULL)
		return (0);

	else if (position == 1)
	{
		*head = current->next;	// advance the head one position (with *head, the content of the pointer **head) // same as: head = head->next
		free(current);
		current = NULL;
	}
	else
	{
		while (i < position)
		{
			previous = current;			// start equaling both pointers
			current = current->next;	// advance current (current will be one ahead when exiting the loop)
			i++;
		}
		previous->next = current->next;	// at loop exit, the current node is skipped. Previous is linked to the next node.
		free(current);					// delete the node
		current = NULL;					// point to null
	}
	return (head);
}

// delete entire list
t_node	*del_list(t_node *head)
{
	t_node	*temp;

	temp = head;

	if (head == NULL)
		return (0);		// list is already empty

	while (temp != NULL)
	{
		temp = temp->next;		// advance to the next node // could also be head = head->next
		free(head);
		head = temp;			// update the value of head and bring it to the next node
	}							// when temp->next is NULL, temp will be NULL and head will be NULL
	return (head);
}




int	main(void)
{
	t_node *head;
	int data;

	head = ft_lstnew();
	count_of_nodes(head);

	head = add_beg_1(head, data);	// method 1, I need to return the updated value of head to main
	add_beg_2(&head, data);			// I am sending the address, so value will get updated in the other function and transferred here




	return (0);
}
