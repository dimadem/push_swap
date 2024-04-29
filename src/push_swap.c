/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmdemirk <dmdemirk@student.42london.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 12:20:47 by dmdemirk          #+#    #+#             */
/*   Updated: 2024/04/28 17:20:42 by dmdemirk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

static void	sort(t_stack_node **stack_a, t_stack_node **stack_b);

int	main(int argc, char **argv)
{
	t_stack_node	*stack_a;
	t_stack_node	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	if (argc == 1 || (argc == 2 && !argv[1][0]))
		return (EXIT_SUCCESS);
	else if (2 == argc)
		argv = ft_split(argv[1], ' ');
	stack_init(&stack_a, argc, argv);
	sort(&stack_a, &stack_b);
	return (EXIT_SUCCESS);
}

static void	sort(t_stack_node **stack_a, t_stack_node **stack_b)
{
	int	fd;

	fd = file_open("temp_cmds.txt");
	if (!(stack_is_sorted(*stack_a)))
	{
		if (ft_stacksize(*stack_a) == 2)
			swap_a(stack_a, true, fd);
		else if (ft_stacksize(*stack_a) == 3)
			sort_three(stack_a, fd);
		else if (ft_stacksize(*stack_a) > 3)
			sort_turk(stack_a, stack_b, fd);
		output_from_file();
		free_stack(stack_a);
		free_stack(stack_b);
	}
	close(fd);
}
