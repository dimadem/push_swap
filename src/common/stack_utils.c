/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmdemirk <dmdemirk@student.42london.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 12:54:04 by dmdemirk          #+#    #+#             */
/*   Updated: 2024/04/26 18:02:46 by dmdemirk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

int			ft_stacksize(t_stack_node *node);
long int	ft_atol(char *str);
int			check_syntax(char *str);
bool		stack_is_sorted(t_stack_node *stack);
int			check_repetition(t_stack_node *stack, int nbr);

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

long int	ft_atol(char *str)
{
	long int	result;
	int			sign;
	int			i;

	result = 0;
	sign = 1;
	i = 0;
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + (str[i] - '0');
		i++;
	}
	return (sign * result);
}

int	check_syntax(char *str_n)
{
	if (!(*str_n == '+'
			|| *str_n == '-'
			|| (*str_n >= '0' && *str_n <= '9')))
		error();
	if ((*str_n == '+' || *str_n == '-')
		&& !(str_n[1] >= '0' && str_n[1] <= '9'))
		error();
	while (*++str_n)
	{
		if (!(*str_n >= '0' && *str_n <= '9'))
			error();
	}
	return (0);
}

bool	stack_is_sorted(t_stack_node *stack)
{
	if (!stack)
		return (false);
	while (stack->next)
	{
		if (stack->value > stack->next->value)
			return (false);
		stack = stack->next;
	}
	return (true);
}

int	check_repetition(t_stack_node *stack, int nbr)
{
	if (stack == NULL)
		return (EXIT_SUCCESS);
	while (stack)
	{
		if (stack->value == nbr)
			error();
		stack = stack->next;
	}
	return (EXIT_SUCCESS);
}
