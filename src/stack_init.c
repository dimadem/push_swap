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
			ft_printf("not a number\n");
		nbr = ft_atol(argv[i]);
		if (INT_MIN > nbr || nbr > INT_MAX)
			ft_printf("less or more than INT	->	%d\n", nbr);	
		if (check_repetition(*stack, (int)nbr))
			ft_printf("this number is already in stack!\n");
		add_node(stack, (int)nbr);
		ft_printf("nbr[%d]		->	%d\n", i, nbr);
	}
	ft_printf("\nstack values\n");
	t_stack_node	*temp_node;
	temp_node = *stack;
	while (temp_node != NULL)
	{
		ft_printf("current 	->	%p\n", temp_node);
		ft_printf("value	->	%d\n", temp_node->value);
		ft_printf("prev		->	%p\n", temp_node->prev);
		ft_printf("next		->	%p\n", temp_node->next);
		temp_node = temp_node->next;
	}

}

void	add_node(t_stack_node **head, int nbr)
{
	t_stack_node	*new_node;	
	t_stack_node	*temp_node_last;

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
	temp_node_last = *head;
	while (temp_node_last->next != NULL)
		temp_node_last = temp_node_last->next;
	temp_node_last->next = new_node;
	new_node->prev = temp_node_last;
}
