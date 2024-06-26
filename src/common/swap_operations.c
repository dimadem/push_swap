/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_operations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmdemirk <dmdemirk@student.42london.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 12:21:04 by dmdemirk          #+#    #+#             */
/*   Updated: 2024/04/28 16:20:25 by dmdemirk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

static void	swap(t_stack_node **head);

void	swap_a(t_stack_node **stack_a, bool checker, int fd)
{
	swap(stack_a);
	if (checker)
		write(fd, "sa\n", 3);
}

void	swap_b(t_stack_node **stack_b, bool checker, int fd)
{
	swap(stack_b);
	if (checker)
		write(fd, "sb\n", 3);
}

void	swap_s(t_stack_node **stack_a,
		t_stack_node **stack_b, bool checker, int fd)
{
	swap(stack_a);
	swap(stack_b);
	if (checker)
		write(fd, "ss\n", 3);
}

static void	swap(t_stack_node **head)
{
	int	len;

	len = ft_stacksize(*head);
	if (*head == NULL || head == NULL || 1 == len)
		return ;
	*head = (*head)->next;
	(*head)->prev->prev = *head;
	(*head)->prev->next = (*head)->next;
	if ((*head)->next)
		(*head)->next->prev = (*head)->prev;
	(*head)->next = (*head)->prev;
	(*head)->prev = NULL;
}
