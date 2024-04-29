/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmdemirk <dmdemirk@student.42london.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 12:21:32 by dmdemirk          #+#    #+#             */
/*   Updated: 2024/04/28 16:33:55 by dmdemirk         ###   ########.fr       */
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
	long int		value;
	int				index;
	int				above_median;
	int				cost;
	int				cheapest;
	struct s_node	*target;
	struct s_node	*prev;
	struct s_node	*next;
}				t_stack_node;

void			push_a(t_stack_node **stack_a,
					t_stack_node **stack_b, bool checker, int fd);
void			push_b(t_stack_node **stack_b,
					t_stack_node **stack_a, bool checker, int fd);

void			swap_a(t_stack_node **stack_a, bool checker, int fd);
void			swap_b(t_stack_node **stack_b, bool checker, int fd);
void			swap_s(t_stack_node **stack_a,
					t_stack_node **stack_b, bool checker, int fd);

void			rotate_a(t_stack_node **stack_a, bool checker, int fd);
void			rotate_b(t_stack_node **stack_b, bool checker, int fd);
void			rotate_r(t_stack_node **stack_a,
					t_stack_node **stack_b, bool checker, int fd);

void			reverse_rotate_a(t_stack_node **stack_a, bool checker, int fd);
void			reverse_rotate_b(t_stack_node **stack_b, bool checker, int fd);
void			reverse_rotate_r(t_stack_node **stack_a,
					t_stack_node **stack_b, bool checker, int fd);

void			stack_init(t_stack_node **stack, int argc, char **argv);
bool			stack_is_sorted(t_stack_node *stack);
long int		ft_atol(char *str);
int				check_syntax(char *str);
int				check_repetition(t_stack_node *stack, int nbr);
int				ft_stacksize(t_stack_node *stack);

int				file_open(char *file);
int				file_open_old(char *file);
void			set_index_stack(t_stack_node **stack);
void			set_cheapest(t_stack_node **stack);
t_stack_node	*get_cheapest(t_stack_node **stack);
t_stack_node	*find_last_node(t_stack_node *head);
t_stack_node	*find_max_node(t_stack_node *stack);
t_stack_node	*find_min_node(t_stack_node *stack);
void			output_from_file(void);

void			sort_three(t_stack_node **stack_a, int fd);
void			sort_turk(t_stack_node **stack_a,
					t_stack_node **stack_b, int fd);

void			set_values_stack_a(t_stack_node **stack_a,
					t_stack_node **stack_b);
void			set_values_stack_b(t_stack_node **stack_b,
					t_stack_node **stack_a);
void			cheapest_push_a(t_stack_node **stack_a,
					t_stack_node **stack_b, int fd);
void			cheapest_push_b(t_stack_node **stack_b,
					t_stack_node **stack_a, int fd);
void			cheapest_top_a(t_stack_node **stack_a,
					t_stack_node *cheapest, int fd);
void			cheapest_top_b(t_stack_node **stack_b,
					t_stack_node *cheapest, int fd);
void			free_2d_arr(char **argv);
void			free_stack(t_stack_node **stack);
void			error_free(t_stack_node **stack, char **argv);

void			error(void);

#endif
