/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakawamo <hakawamo@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/06 03:50:27 by hakawamo          #+#    #+#             */
/*   Updated: 2025/07/07 06:13:19 by hakawamo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three(t_stack **head)
{
	int	max_index;

	max_index = find_max_index(*head);
	if ((*head)->index == max_index)
		rotate_a(head);
	else if ((*head)->next->index == max_index)
		r_rotate_a(head);
	if ((*head)->index > (*head)->next->index)
		swap_a(head);
}

void	sort_five(t_stack **stack_a, t_stack **stack_b)
{
	int	size;

	size = count_nodes(*stack_a);
	while (size--)
	{
		if ((*stack_a)->index == 0 || (*stack_a)->index == 1)
			push_b(stack_a, stack_b);
		else
			rotate_a(stack_a);
	}
	sort_three(stack_a);
	push_a(stack_a, stack_b);
	push_a(stack_a, stack_b);
	if ((*stack_a)->index > (*stack_a)->next->index)
		swap_a(stack_a);
}

void	radix_sort(t_stack **stack_a, t_stack **stack_b)
{
	int	max_index;
	int	max_bits;
	int	i;
	int	j;

	max_index = find_max_index(*stack_a);
	max_bits = find_max_bits(max_index);
	i = 0;
	while (i < max_bits)
	{
		j = 0;
		while (j <= max_index)
		{
			if (((*stack_a)->index >> i) & 1)
				rotate_a(stack_a);
			else
				push_b(stack_a, stack_b);
			j++;
		}
		while (*stack_b)
			push_a(stack_a, stack_b);
		i++;
	}
}

void	sort_stack(t_stack **stack_a, t_stack **stack_b)
{
	int	size;

	size = count_nodes(*stack_a);
	if (!sorted(stack_a) && size <= 3)
		sort_three(stack_a);
	else if (!sorted(stack_a) && size <= 5)
		sort_five(stack_a, stack_b);
	else if (!sorted(stack_a))
		radix_sort(stack_a, stack_b);
	else
	{
		free_stack(stack_a);
		free_stack(stack_b);
	}
}
