/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmdemirk <dmdemirk@student.42london.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 18:54:00 by dmdemirk          #+#    #+#             */
/*   Updated: 2024/04/22 18:55:13 by dmdemirk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	print_stack(t_stack_node **stack)
{
	t_stack_node	*temp_node;

	temp_node = *stack;
	while (temp_node != NULL)
	{
		ft_printf("\n\n---NODE---\n");
		ft_printf("current 	->	%p\n", temp_node);
		ft_printf("value	->	%d\n", temp_node->value);
		ft_printf("prev		->	%p\n", temp_node->prev);
		ft_printf("next		->	%p\n", temp_node->next);
		temp_node = temp_node->next;
	}
}
