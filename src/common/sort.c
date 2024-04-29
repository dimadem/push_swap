/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmdemirk <dmdemirk@student.42london.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 11:43:35 by dmdemirk          #+#    #+#             */
/*   Updated: 2024/04/26 18:09:23 by dmdemirk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

void	sort_min(t_stack_node **stack_a, int fd);
void	sort_three(t_stack_node **stack_a, int fd);
void	sort_turk(t_stack_node **stack_a, t_stack_node **stack_b, int fd);

void	sort_min(t_stack_node **stack_a, int fd)
{
	t_stack_node	*min;

	min = find_min_node(*stack_a);
	while (*stack_a != min)
	{
		if (min->above_median)
			rotate_a(stack_a, true, fd);
		else
			reverse_rotate_a(stack_a, true, fd);
	}
}

void	sort_three(t_stack_node **stack_a, int fd)
{
	long int		first;
	long int		second;
	long int		third;

	first = (*stack_a)->value;
	second = (*stack_a)->next->value;
	third = (*stack_a)->next->next->value;
	if (first > second && second < third && first < third)
		swap_a(stack_a, true, fd);
	else if (first > second && second > third)
	{
		swap_a(stack_a, true, fd);
		reverse_rotate_a(stack_a, true, fd);
	}
	else if (first < second && second > third && first < third)
	{
		swap_a(stack_a, true, fd);
		rotate_a(stack_a, true, fd);
	}
	else if (first > second && second < third && first > third)
		rotate_a(stack_a, true, fd);
	else if (first < second && second > third && first > third)
		reverse_rotate_a(stack_a, true, fd);
}

void	sort_turk(t_stack_node **stack_a, t_stack_node **stack_b, int fd)
{
	int	size;

	size = ft_stacksize(*stack_a);
	if (size-- > 3 && !stack_is_sorted(*stack_a))
		push_b(stack_b, stack_a, true, fd);
	if (size-- > 3 && !stack_is_sorted(*stack_a))
		push_b(stack_b, stack_a, true, fd);
	while (size > 3 && !stack_is_sorted(*stack_a))
	{
		set_values_stack_a(stack_a, stack_b);
		cheapest_push_a(stack_a, stack_b, fd);
		--size;
	}
	sort_three(stack_a, fd);
	while (*stack_b)
	{
		set_values_stack_b(stack_b, stack_a);
		cheapest_push_b(stack_b, stack_a, fd);
	}
	set_index_stack(stack_a);
	sort_min(stack_a, fd);
}
