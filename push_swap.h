/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakawamo <hakawamo@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/06 03:43:32 by hakawamo          #+#    #+#             */
/*   Updated: 2025/07/07 06:13:26 by hakawamo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include <limits.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_stack
{
	int				value;
	int				index;
	struct s_stack	*next;
}					t_stack;

t_stack				*init_list(int argc, char **argv);
void				set_index(t_stack *head, int total_nodes);

int					count_nodes(t_stack *head);
void				print_list(t_stack *head);
void				append_node(t_stack **head, int new_value);
t_stack				*create_node(int new_value);

void				swap(t_stack **head);
void				swap_a(t_stack **head);
void				swap_b(t_stack **head);
void				swap_ab(t_stack **stack_a, t_stack **stack_b);
void				push(t_stack **stack_from, t_stack **stack_to);
void				push_a(t_stack **stack_a, t_stack **stack_b);
void				push_b(t_stack **stack_a, t_stack **stack_b);
void				rotate(t_stack **head);
void				rotate_a(t_stack **head);
void				rotate_b(t_stack **head);
void				rotate_ab(t_stack **stack_a, t_stack **stack_b);
void				r_rotate(t_stack **head);
void				r_rotate_a(t_stack **head);
void				r_rotate_b(t_stack **head);
void				r_rotate_ab(t_stack **stack_a, t_stack **stack_b);

int					find_max_index(t_stack *head);
int					find_max_bits(int max_index);
void				sort_three(t_stack **head);
void				sort_five(t_stack **stack_a, t_stack **stack_b);
void				radix_sort(t_stack **stack_a, t_stack **stack_b);
void				sort_stack(t_stack **stack_a, t_stack **stack_b);
int					sorted(t_stack **head);

void				check_input(int argc, char **argv);
int					is_valid_number(char *argv);
int					is_duplicate(char **argv);

void				exit_error(char *str);
void				free_stack(t_stack **head);
int					count_arg(char **array);
long				ft_atol(const char *str);
void				ft_free(char **arr);

#endif