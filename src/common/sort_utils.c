/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmdemirk <dmdemirk@student.42london.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 12:04:23 by dmdemirk          #+#    #+#             */
/*   Updated: 2024/04/26 18:09:27 by dmdemirk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

void			set_index_stack(t_stack_node **stack);
void			set_cheapest(t_stack_node **stack);
t_stack_node	*get_cheapest(t_stack_node **stack);

void	set_index_stack(t_stack_node **stack)
{
	int				i;
	int				size;
	t_stack_node	*temp_node;

	i = 0;
	size = ft_stacksize(*stack);
	temp_node = *stack;
	while (*stack)
	{
		(*stack)->index = i;
		if (i <= size / 2)
			(*stack)->above_median = 1;
		else
			(*stack)->above_median = 0;
		(*stack) = (*stack)->next;
		i++;
	}
	*stack = temp_node;
}

void	set_cheapest(t_stack_node **stack)
{
	long int		cheapest;
	t_stack_node	*temp_node;
	t_stack_node	*cheapest_node;

	if (!*stack)
		return ;
	cheapest = LONG_MAX;
	temp_node = *stack;
	while (temp_node)
	{
		if (temp_node->cost < cheapest)
		{
			cheapest = temp_node->cost;
			cheapest_node = temp_node;
		}
		temp_node->cheapest = 0;
		temp_node = temp_node->next;
	}
	cheapest_node->cheapest = 1;
}

t_stack_node	*get_cheapest(t_stack_node **stack)
{
	t_stack_node	*temp_node;

	if (!*stack)
		return (NULL);
	temp_node = *stack;
	while (temp_node)
	{
		if (temp_node->cheapest == 1)
			return (temp_node);
		temp_node = temp_node->next;
	}
	return (NULL);
}
