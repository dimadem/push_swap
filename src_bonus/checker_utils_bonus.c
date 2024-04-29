/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_utils_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmdemirk <dmdemirk@student.42london.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 12:57:39 by dmdemirk          #+#    #+#             */
/*   Updated: 2024/04/28 16:20:01 by dmdemirk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int			execute_cmds(t_stack_node **stack_a,
				t_stack_node **stack_b, char *cmd, int fd);
static int	execute_swap(t_stack_node **stack_a,
				t_stack_node **stack_b, char *cmd, int fd);
static int	execute_rotate(t_stack_node **stack_a,
				t_stack_node **stack_b, char *cmd, int fd);
static int	execute_reverse_rotate(t_stack_node **stack_a,
				t_stack_node **stack_b, char *cmd, int fd);
static int	execute_push(t_stack_node **stack_a,
				t_stack_node **stack_b, char *cmd, int fd);

int	execute_cmds(t_stack_node **stack_a,
				t_stack_node **stack_b, char *cmd, int fd)
{
	return (execute_swap(stack_a, stack_b, cmd, fd)
		&& execute_rotate(stack_a, stack_b, cmd, fd)
		&& execute_reverse_rotate(stack_a, stack_b, cmd, fd)
		&& execute_push(stack_a, stack_b, cmd, fd));
}

static int	execute_swap(t_stack_node **stack_a,
				t_stack_node **stack_b, char *cmd, int fd)
{
	if (!ft_strncmp(cmd, "sa\n", ft_strlen("sa\n")))
	{
		swap_a(stack_a, true, fd);
		return (EXIT_SUCCESS);
	}
	else if (!ft_strncmp(cmd, "sb\n", ft_strlen("sb\n")))
	{
		swap_b(stack_b, true, fd);
		return (EXIT_SUCCESS);
	}
	else if (!ft_strncmp(cmd, "ss\n", ft_strlen("ss\n")))
	{
		swap_s(stack_a, stack_b, true, fd);
		return (EXIT_SUCCESS);
	}
	else
		return (EXIT_FAILURE);
}

static int	execute_rotate(t_stack_node **stack_a,
				t_stack_node **stack_b, char *cmd, int fd)
{
	if (!ft_strncmp(cmd, "ra\n", ft_strlen("ra\n")))
	{
		rotate_a(stack_a, true, fd);
		return (EXIT_SUCCESS);
	}
	else if (!ft_strncmp(cmd, "rb\n", ft_strlen("rb\n")))
	{
		rotate_b(stack_b, true, fd);
		return (EXIT_SUCCESS);
	}
	else if (!ft_strncmp(cmd, "rr\n", ft_strlen("rr\n")))
	{
		rotate_r(stack_a, stack_b, true, fd);
		return (EXIT_SUCCESS);
	}
	else
		return (EXIT_FAILURE);
}

static int	execute_reverse_rotate(t_stack_node **stack_a,
				t_stack_node **stack_b, char *cmd, int fd)
{
	if (!ft_strncmp(cmd, "rra\n", ft_strlen("rra\n")))
	{
		reverse_rotate_a(stack_a, true, fd);
		return (EXIT_SUCCESS);
	}
	else if (!ft_strncmp(cmd, "rrb\n", ft_strlen("rrb\n")))
	{
		reverse_rotate_b(stack_b, true, fd);
		return (EXIT_SUCCESS);
	}
	else if (!ft_strncmp(cmd, "rrr\n", ft_strlen("rrr\n")))
	{
		reverse_rotate_r(stack_a, stack_b, true, fd);
		return (EXIT_SUCCESS);
	}
	else
		return (EXIT_FAILURE);
}

static int	execute_push(t_stack_node **stack_a,
				t_stack_node **stack_b, char *cmd, int fd)
{
	if (!ft_strncmp(cmd, "pa\n", ft_strlen("pa\n")))
	{
		push_a(stack_a, stack_b, true, fd);
		return (EXIT_SUCCESS);
	}
	else if (!ft_strncmp(cmd, "pb\n", ft_strlen("pb\n")))
	{
		push_b(stack_b, stack_a, true, fd);
		return (EXIT_SUCCESS);
	}
	else
		return (EXIT_FAILURE);
}
