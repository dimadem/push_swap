/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm_stack_b_utils.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmdemirk <dmdemirk@student.42london.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 11:48:16 by dmdemirk          #+#    #+#             */
/*   Updated: 2024/04/26 18:03:29 by dmdemirk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

void	set_values_stack_b(t_stack_node **stack_b, t_stack_node **stack_a);
void	set_target_stack_b(t_stack_node **stack_b, t_stack_node **stack_a);
void	cheapest_top_b(t_stack_node **stack_b, t_stack_node *cheapest, int fd);
void	cheapest_push_b(t_stack_node **stack_b, t_stack_node **stack_a, int fd);

void	set_values_stack_b(t_stack_node **stack_b, t_stack_node **stack_a)
{
	set_index_stack(stack_a);
	set_index_stack(stack_b);
	set_target_stack_b(stack_b, stack_a);
}

void	set_target_stack_b(t_stack_node **stack_b, t_stack_node **stack_a)
{
	t_stack_node	*temp_stack_a;
	t_stack_node	*temp_stack_b;
	long int		closest;

	temp_stack_b = *stack_b;
	while (temp_stack_b)
	{
		closest = LONG_MAX;
		temp_stack_a = *stack_a;
		while (temp_stack_a)
		{
			if ((temp_stack_b->value < temp_stack_a->value)
				&& (temp_stack_a->value < closest))
			{
				temp_stack_b->target = temp_stack_a;
				closest = temp_stack_a->value;
			}
			temp_stack_a = temp_stack_a->next;
		}
		if (closest == LONG_MAX)
			temp_stack_b->target = find_min_node(*stack_a);
		temp_stack_b = temp_stack_b->next;
	}
}

void	cheapest_top_b(t_stack_node **stack_b, t_stack_node *cheapest, int fd)
{
	if (!*stack_b || !cheapest)
		return ;
	while (*stack_b != cheapest)
	{
		if (cheapest->above_median)
			rotate_b(stack_b, true, fd);
		else
			reverse_rotate_b(stack_b, true, fd);
	}
}

void	cheapest_push_b(t_stack_node **stack_b, t_stack_node **stack_a, int fd)
{
	cheapest_top_a(stack_a, (*stack_b)->target, fd);
	push_a(stack_a, stack_b, true, fd);
}
