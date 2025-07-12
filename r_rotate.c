/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   r_rotate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakawamo <hakawamo@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/06 03:50:16 by hakawamo          #+#    #+#             */
/*   Updated: 2025/07/06 21:13:02 by hakawamo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	r_rotate(t_stack **head)
{
	t_stack	*old_tail;
	t_stack	*new_tail;

	if (*head == NULL || (*head)->next == NULL)
		return ;
	old_tail = *head;
	while (old_tail->next != NULL)
	{
		new_tail = old_tail;
		old_tail = old_tail->next;
	}
	old_tail->next = *head;
	new_tail->next = NULL;
	*head = old_tail;
}

void	r_rotate_a(t_stack **head)
{
	r_rotate(head);
	write(1, "rra\n", 4);
}

void	r_rotate_b(t_stack **head)
{
	r_rotate(head);
	write(1, "rrb\n", 4);
}

void	r_rotate_ab(t_stack **stack_a, t_stack **stack_b)
{
	r_rotate(stack_a);
	r_rotate(stack_b);
	write(1, "rrr\n", 4);
}
