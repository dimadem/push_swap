/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_operations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmdemirk <dmdemirk@student.42london.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 12:20:43 by dmdemirk          #+#    #+#             */
/*   Updated: 2024/04/22 18:52:21 by dmdemirk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

static void	push(t_stack_node **dest, t_stack_node **src);

void	push_a(t_stack_node **stack_a, t_stack_node **stack_b, bool checker)
{
	push(stack_a, stack_b);
	if (!checker)
		write(1, "pa\n", 3);
}

void	push_b(t_stack_node **stack_b, t_stack_node **stack_a, bool checker)
{
	push(stack_b, stack_a);
	if (!checker)
		write(1, "pb\n", 3);
}

static void	push(t_stack_node **dest, t_stack_node **src)
{
	t_stack_node	*push_node;

	if (*src == NULL)
		return ;
	push_node = *src;
	*src = (*src)->next;
	if (*src)
		(*src)->prev = NULL;
	push_node->prev = NULL;
	if (*dest == NULL)
	{
		*dest = push_node;
		push_node->next = NULL;
	}
	else
	{
		push_node->next = *dest;
		push_node->next->prev = push_node;
		*dest = push_node;
	}
}
