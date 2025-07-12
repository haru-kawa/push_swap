/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakawamo <hakawamo@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/06 03:49:59 by hakawamo          #+#    #+#             */
/*   Updated: 2025/07/07 05:05:41 by hakawamo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	set_index(t_stack *head, int total_nodes)
{
	t_stack	*max_unindexed_node;
	t_stack	*current;

	while (total_nodes-- > 0)
	{
		max_unindexed_node = NULL;
		current = head;
		while (current)
		{
			if (!current->index && (max_unindexed_node == NULL
					|| current->value > max_unindexed_node->value))
				max_unindexed_node = current;
			current = current->next;
		}
		if (max_unindexed_node)
			max_unindexed_node->index = total_nodes;
	}
}

t_stack	*init_list(int argc, char **argv)
{
	t_stack	*stack_a;
	char	**tmp;
	int		i;

	stack_a = NULL;
	i = 0;
	if (argc == 2)
		tmp = ft_split(argv[1], ' ');
	else
	{
		i = 1;
		tmp = argv;
	}
	while (tmp[i])
	{
		append_node(&stack_a, ft_atol(tmp[i]));
		i++;
	}
	if (argc == 2)
		ft_free(tmp);
	return (stack_a);
}
