/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmdemirk <dmdemirk@student.42london.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 18:25:19 by dmdemirk          #+#    #+#             */
/*   Updated: 2024/04/25 14:24:41 by dmdemirk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

void	free_2d_arr(char **argv);
void	free_stack(t_stack_node **stack);
void	error_free(t_stack_node **stack_a, char **argv);

void	free_2d_arr(char **argv)
{
	int	i;

	i = -1;
	if (argv == NULL || *argv == NULL)
		return ;
	while (argv[i])
		free(argv[i++]);
	free(argv - 1);
}

void	free_stack(t_stack_node **stack)
{
	t_stack_node	*tmp;
	t_stack_node	*curr;

	if (stack == NULL)
		return ;
	curr = *stack;
	while (curr)
	{
		tmp = curr->next;
		free(curr);
		curr = tmp;
	}
	*stack = NULL;
}

void	error_free(t_stack_node **stack_a, char **argv)
{
	free_stack(stack_a);
	free_2d_arr(argv);
	write(2, "Error\n", 6);
	exit(1);
}
