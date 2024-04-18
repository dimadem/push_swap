/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate_operations.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmdemirk <dmdemirk@student.42london.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 12:20:53 by dmdemirk          #+#    #+#             */
/*   Updated: 2024/04/17 12:53:50 by dmdemirk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

static void	reverse_rotate(t_stack_node **stack);

void	reverse_rotate_a(t_stack_node **stack_a, bool checker)
{
	reverse_rotate(stack_a);
	if (!checker)
		write(1, "rra\n", 4);
}

void	reverse_rotate_b(t_stack_node **stack_b, bool checker)
{
	reverse_rotate(stack_b);
	if (!checker)
		write(1, "rrb\n", 4);
}

void	reverse_rotate_r(t_stack_node **stack_a, t_stack_node **stack_b, bool checker)
{
	reverse_rotate(stack_a);
	reverse_rotate(stack_b);
	if (!checker)
		write(1, "rrr\n", 4);
}

static void	reverse_rotate(t_stack_node **stack)
{
	t_stack_node	*last_node;
	int	len;

	len = ft_stacksize(*stack);
	if (*stack == NULL || 1 == len)
		return ;
	last_node = find_last_node(*stack);
	last_node->prev->next = NULL;
	last_node->next = *stack;
	last_node->prev = NULL;
	*stack = last_node;
	last_node->next->prev = last_node;
}
