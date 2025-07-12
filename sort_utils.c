/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakawamo <hakawamo@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/06 03:50:25 by hakawamo          #+#    #+#             */
/*   Updated: 2025/07/07 06:13:44 by hakawamo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_max_index(t_stack *head)
{
	int		max_index;
	t_stack	*current;

	max_index = INT_MIN;
	current = head;
	while (current)
	{
		if (current->index > max_index)
			max_index = current->index;
		current = current->next;
	}
	return (max_index);
}

int	find_max_bits(int max_index)
{
	int	max_bits;

	max_bits = 0;
	while (max_index > 0)
	{
		max_index >>= 1;
		max_bits++;
	}
	return (max_bits);
}
