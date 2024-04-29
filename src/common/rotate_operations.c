/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_operations.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmdemirk <dmdemirk@student.42london.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 12:20:19 by dmdemirk          #+#    #+#             */
/*   Updated: 2024/04/28 16:22:12 by dmdemirk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

static void	rotate(t_stack_node **stack);

void	rotate_a(t_stack_node **stack_a, bool checker, int fd)
{
	rotate(stack_a);
	if (checker)
		write(fd, "ra\n", 3);
}

void	rotate_b(t_stack_node **stack_b, bool checker, int fd)
{
	rotate(stack_b);
	if (checker)
		write(fd, "rb\n", 3);
}

void	rotate_r(t_stack_node **stack_a,
			t_stack_node **stack_b, bool checker, int fd)
{
	rotate(stack_a);
	rotate(stack_b);
	if (checker)
		write(fd, "rr\n", 3);
}

static void	rotate(t_stack_node **stack)
{
	t_stack_node	*last_node;
	int				len;

	len = ft_stacksize(*stack);
	if (*stack == NULL || 1 == len)
		return ;
	last_node = find_last_node(*stack);
	last_node->next = *stack;
	*stack = (*stack)->next;
	(*stack)->prev = NULL;
	last_node->next->prev = last_node;
	last_node->next->next = NULL;
}
