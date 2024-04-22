/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmdemirk <dmdemirk@student.42london.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 12:20:47 by dmdemirk          #+#    #+#             */
/*   Updated: 2024/04/22 19:24:13 by dmdemirk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"
#include "debug_utils.h"

int	main(int argc, char **argv)
{
	t_stack_node	*stack_a;
	//	t_stack_node	*stack_b;

	stack_a = NULL;
	//	stack_b = NULL;
	ft_printf("argc			->	%d\n", argc);
	ft_printf("argv[0]		->	%s\n", argv[0]);
	ft_printf("argv[1]		->	%s\n", argv[1]);
	ft_printf("argv[2]		->	%s\n", argv[2]);
	ft_printf("argv[3]		->	%s\n", argv[3]);
	ft_printf("argv[4]		->	%s\n", argv[4]);
	ft_printf("argv[5]		->	%s\n", argv[5]);
	if (argc == 1 || (argc == 2 && !argv[1][0]))
		return (EXIT_FAILURE);
	else if (2 == argc)
		argv = ft_split(argv[1], ' ');
	stack_init(&stack_a, argv);
	if (!(stack_is_sorted(stack_a)))
	{
		ft_printf("\n");
		reverse_rotate_a(&stack_a, 0);
		ft_printf("\n");
		print_stack(&stack_a);
	}
	else 
		ft_printf("\nnothing to sort\n");
	return (EXIT_SUCCESS);
}
