/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmdemirk <dmdemirk@student.42london.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 12:21:32 by dmdemirk          #+#    #+#             */
/*   Updated: 2024/04/17 18:29:51 by dmdemirk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../external/ft_printf/src/ft_printf.h"

typedef struct s_node
{
	int				value;
	struct s_node	*prev;
	struct s_node	*next;
}				t_stack_node;

void		stack_init(t_stack_node **stack, char **argv);
long int	ft_atol(char *str);
int			check_syntax(char *str);
int	check_repetition(t_stack_node *stack, int nbr);

#endif
