/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmdemirk <dmdemirk@student.42london.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 12:54:08 by dmdemirk          #+#    #+#             */
/*   Updated: 2024/04/17 18:32:54 by dmdemirk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"
#include "debug_utils.h"

void	add_node(t_stack_node **stack, int nbr);

void	stack_init(t_stack_node **stack, char **argv)
{
	long	nbr;
	int		i;

	ft_printf("\nstack init\n");
	i = -1;
	while(argv[++i])
	{
		if (check_syntax(argv[i]))
			error();
		nbr = ft_atol(argv[i]);
		if (INT_MIN > nbr || nbr > INT_MAX)
			error();
		if (check_repetition(*stack, (int)nbr))
			error();
		add_node(stack, (int)nbr);
		ft_printf("nbr[%d]		->	%d\n", i, nbr);
	}
	ft_printf("\nstack values\n");
	print_stack(stack);
}

void	add_node(t_stack_node **head, int nbr)
{
	t_stack_node	*new_node;	
	t_stack_node	*curr_node;

	ft_printf("\nadd node\n");
	new_node = (t_stack_node *)malloc(sizeof(t_stack_node));
	if (!new_node)
		return ;
	new_node->value = nbr;
	new_node->prev = NULL;
	new_node->next = NULL;
	if (*head == NULL)
	{
		*head = new_node;
		return ;
	}
	curr_node = *head;
	while (curr_node->next != NULL)
		curr_node = curr_node->next;
	curr_node->next = new_node;
	new_node->prev = curr_node;
}
