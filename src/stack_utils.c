/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmdemirk <dmdemirk@student.42london.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 12:54:04 by dmdemirk          #+#    #+#             */
/*   Updated: 2024/04/17 18:31:44 by dmdemirk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	ft_stacksize(t_stack_node *node)
{
	int	size;

	size = 0;
	while (node)
	{
		node = node->next;
		size++;
	}
	return (size);
}

t_stack_node	*find_last_node(t_stack_node *head)
{
	if(head == NULL)
		return (NULL);
	while(head->next)
		head = head->next;
	return (head);
}

long int	ft_atol(char *str)
{
	long int result = 0;
	int sign = 1;
	int i = 0;

	// Skip leading whitespace
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n')
	{
		i++;
	}

	// Check for sign
	if (str[i] == '-' || str[i] == '+')
	{
		sign = (str[i] == '-') ? -1 : 1;
		i++;
	}

	// Convert string to long int
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + (str[i] - '0');
		i++;
	}

	return (sign * result);
}

int	check_syntax(char *str)
{
	int	i;

	i = 0;
	if(str[i] == '-' || str[i] == '+')
		++i;
	while(str[i])
	{
		if (!('0' <= str[i] && str[i] <= '9'))
			return (EXIT_FAILURE);
		++i;
	}
	return (EXIT_SUCCESS);
}

int	check_repetition(t_stack_node *stack, int nbr)
{
	if (stack == NULL)
		return (EXIT_SUCCESS);
	while(stack)
	{
		if (stack->value == nbr)
			return (EXIT_FAILURE);
		stack = stack->next;
	}
	return (EXIT_SUCCESS);
}
