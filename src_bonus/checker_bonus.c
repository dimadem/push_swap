/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmdemirk <dmdemirk@student.42london.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 12:35:30 by dmdemirk          #+#    #+#             */
/*   Updated: 2024/04/28 13:51:29 by dmdemirk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"
#include "../inc/checker_bonus.h"

static void	get_cmds(t_stack_node **stack_a, t_stack_node **stack_b);
static void	check_stack_is_sorted(t_stack_node **stack_a,
				t_stack_node **stack_b);

int	main(int argc, char **argv)
{
	t_stack_node	*stack_a;
	t_stack_node	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	if (argc < 2)
		return (EXIT_FAILURE);
	stack_init(&stack_a, argc, argv);
	get_cmds(&stack_a, &stack_b);
	check_stack_is_sorted(&stack_a, &stack_b);
}

static void	get_cmds(t_stack_node **stack_a, t_stack_node **stack_b)
{
	char	*cmd;
	int		fd;

	fd = file_open_old("temp_cmds.txt");
	cmd = ft_get_next_line(STDIN_FILENO);
	while (cmd != NULL)
	{
		if (execute_cmds(stack_a, stack_b, cmd, fd))
		{
			free(cmd);
			free_stack(stack_a);
			free_stack(stack_b);
			return ;
		}
		free(cmd);
		cmd = ft_get_next_line(STDIN_FILENO);
	}
}

static void	check_stack_is_sorted(t_stack_node **stack_a,
				t_stack_node **stack_b)
{
	if (stack_is_sorted(*stack_a) && *stack_b == NULL)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
}
