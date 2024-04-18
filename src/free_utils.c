#include "../inc/push_swap.h"

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
	//	if (flag_argc_2)
	free_2d_arr(argv);
	write(2, "Error\n", 6);
	exit(1);
}

