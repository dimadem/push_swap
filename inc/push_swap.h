/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmdemirk <dmdemirk@student.42london.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 12:21:32 by dmdemirk          #+#    #+#             */
/*   Updated: 2024/04/22 19:15:13 by dmdemirk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../external/ft_printf/src/ft_printf.h"

# include <stdbool.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_node
{
	int				value;
	struct s_node	*prev;
	struct s_node	*next;
}				t_stack_node;

void			push_a(t_stack_node **stack_a,
					t_stack_node **stack_b, bool checker);
void			push_b(t_stack_node **stack_b,
					t_stack_node **stack_a, bool checker);

void			swap_a(t_stack_node **stack_a, bool checker);
void			swap_b(t_stack_node **stack_b, bool checker);
void			swap_s(t_stack_node **stack_a,
					t_stack_node **stack_b, bool checker);

void			rotate_a(t_stack_node **stack_a, bool checker);
void			rotate_b(t_stack_node **stack_b, bool checker);
void			rotate_r(t_stack_node **stack_a,
					t_stack_node **stack_b, bool checker);

void			reverse_rotate_a(t_stack_node **stack_a, bool checker);
void			reverse_rotate_b(t_stack_node **stack_b, bool checker);
void			reverse_rotate_r(t_stack_node **stack_a,
					t_stack_node **stack_b, bool checker);

void			stack_init(t_stack_node **stack, char **argv);
bool			stack_is_sorted(t_stack_node *stack);
long int		ft_atol(char *str);
int				check_syntax(char *str);
int				check_repetition(t_stack_node *stack, int nbr);
int				ft_stacksize(t_stack_node *stack);
t_stack_node	*find_last_node(t_stack_node *head);

void			free_2d_arr(char **argv);
void			free_stack(t_stack_node **stack);
void			error_free(t_stack_node **stack, char **argv);

void			error(void);

#endif
