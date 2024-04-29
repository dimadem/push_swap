/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmdemirk <dmdemirk@student.42london.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 12:54:08 by dmdemirk          #+#    #+#             */
/*   Updated: 2024/04/26 18:09:31 by dmdemirk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

void			stack_init(t_stack_node **stack, int argc, char **argv);
void			add_node(t_stack_node **stack, int nbr);
bool			stack_is_sorted(t_stack_node *stack);
t_stack_node	*find_last_node(t_stack_node *head);
t_stack_node	*find_max_node(t_stack_node *stack);
t_stack_node	*find_min_node(t_stack_node *stack);

void	stack_init(t_stack_node **stack, int argc, char **argv)
{
	long	nbr;
	int		i;

	if (argc != 2)
		i = 0;
	else
		i = -1;
	while (argv[++i])
	{
		if (check_syntax(argv[i]))
			error();
		nbr = ft_atol(argv[i]);
		if (INT_MIN > nbr || nbr > INT_MAX)
			error();
		if (check_repetition(*stack, (int)nbr))
			error();
		add_node(stack, (int)nbr);
	}
}

void	add_node(t_stack_node **head, int nbr)
{
	t_stack_node	*new_node;	
	t_stack_node	*curr_node;

	new_node = (t_stack_node *)malloc(sizeof(t_stack_node));
	if (!new_node)
		return ;
	new_node->value = nbr;
	new_node->index = 0;
	new_node->prev = NULL;
	new_node->next = NULL;
	if (*head == NULL)
	{
		*head = new_node;
		return ;
	}
	curr_node = *head;
	while (curr_node->next != NULL)
		curr_node = curr_node->next;
	curr_node->next = new_node;
	new_node->prev = curr_node;
}

t_stack_node	*find_last_node(t_stack_node *head)
{
	if (head == NULL)
		return (NULL);
	while (head->next)
		head = head->next;
	return (head);
}

t_stack_node	*find_max_node(t_stack_node *stack)
{
	t_stack_node	*max_node;
	long			max;

	if (!stack)
		return (NULL);
	max = LONG_MIN;
	while (stack)
	{
		if (stack->value > max)
		{
			max = stack->value;
			max_node = stack;
		}
		stack = stack->next;
	}
	return (max_node);
}

t_stack_node	*find_min_node(t_stack_node *stack)
{
	t_stack_node	*min_node;
	long			min;

	if (!stack)
		return (NULL);
	min = LONG_MAX;
	while (stack)
	{
		if (stack->value < min)
		{
			min = stack->value;
			min_node = stack;
		}
		stack = stack->next;
	}
	return (min_node);
}
