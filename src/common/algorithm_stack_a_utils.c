/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm_stack_a_utils.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmdemirk <dmdemirk@student.42london.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 14:50:37 by dmdemirk          #+#    #+#             */
/*   Updated: 2024/04/26 18:09:08 by dmdemirk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

void	set_values_stack_a(t_stack_node **stack_a, t_stack_node **stack_b);
void	set_target_stack_a(t_stack_node **stack_a, t_stack_node **stack_b);
void	set_cost_stack_a(t_stack_node **stack_a, t_stack_node *stack_b);
void	cheapest_push_a(t_stack_node **stack_a, t_stack_node **stack_b, int fd);
void	cheapest_top_a(t_stack_node **stack_a, t_stack_node *cheapest, int fd);

void	set_values_stack_a(t_stack_node **stack_a, t_stack_node **stack_b)
{
	set_index_stack(stack_a);
	set_index_stack(stack_b);
	set_target_stack_a(stack_a, stack_b);
	set_cost_stack_a(stack_a, *stack_b);
	set_cheapest(stack_a);
}

void	set_target_stack_a(t_stack_node **stack_a, t_stack_node **stack_b)
{
	t_stack_node	*temp_node_a;
	t_stack_node	*temp_node_b;
	long int		closest;

	temp_node_a = *stack_a;
	while (*stack_a)
	{
		closest = LONG_MIN;
		temp_node_b = *stack_b;
		while (temp_node_b)
		{
			if (((*stack_a)->value > temp_node_b->value)
				&& (temp_node_b->value > closest))
			{
				(*stack_a)->target = temp_node_b;
				closest = temp_node_b->value;
			}
			temp_node_b = temp_node_b->next;
		}
		if (closest == LONG_MIN)
			(*stack_a)->target = find_max_node(*stack_b);
		*stack_a = (*stack_a)->next;
	}
	*stack_a = temp_node_a;
}

void	set_cost_stack_a(t_stack_node **stack_a, t_stack_node *stack_b)
{
	t_stack_node	*temp_node;
	int				len_stack_a;
	int				len_stack_b;

	temp_node = *stack_a;
	len_stack_a = ft_stacksize(*stack_a);
	len_stack_b = ft_stacksize(stack_b);
	while (*stack_a)
	{
		(*stack_a)->cost = (*stack_a)->index;
		if ((*stack_a)->above_median == 0)
			(*stack_a)->cost = len_stack_a - (*stack_a)->index;
		if ((*stack_a)->target->above_median == 1)
			(*stack_a)->cost += (*stack_a)->target->index;
		else
			(*stack_a)->cost += len_stack_b - (*stack_a)->target->index;
		(*stack_a) = (*stack_a)->next;
	}
	*stack_a = temp_node;
}

void	cheapest_push_a(t_stack_node **stack_a, t_stack_node **stack_b, int fd)
{
	t_stack_node	*cheapest;

	cheapest = get_cheapest(stack_a);
	if (cheapest->above_median && cheapest->target->above_median)
	{
		while (*stack_b != cheapest->target && *stack_a != cheapest)
			rotate_r(stack_a, stack_b, true, fd);
		set_index_stack(stack_a);
		set_index_stack(stack_b);
	}
	else if (!(cheapest->above_median) && !(cheapest->target->above_median))
	{
		while (*stack_b != cheapest->target && *stack_a != cheapest)
			reverse_rotate_r(stack_a, stack_b, true, fd);
		set_index_stack(stack_a);
		set_index_stack(stack_b);
	}
	cheapest_top_a(stack_a, cheapest, fd);
	cheapest_top_b(stack_b, cheapest->target, fd);
	push_b(stack_b, stack_a, true, fd);
}

void	cheapest_top_a(t_stack_node **stack_a, t_stack_node *cheapest, int fd)
{
	while (*stack_a != cheapest)
	{
		if (cheapest->above_median)
			rotate_a(stack_a, true, fd);
		else
			reverse_rotate_a(stack_a, true, fd);
	}
}
