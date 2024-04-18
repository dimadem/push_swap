#include "../inc/push_swap.h"

void	print_stack(t_stack_node **stack)
{
	t_stack_node	*temp_node;
	temp_node = *stack;
	while (temp_node != NULL)
	{
		ft_printf("\n\n---NODE---\n");
		ft_printf("current 	->	%p\n", temp_node);
		ft_printf("value	->	%d\n", temp_node->value);
		ft_printf("prev		->	%p\n", temp_node->prev);
		ft_printf("next		->	%p\n", temp_node->next);
		temp_node = temp_node->next;
	}
}
