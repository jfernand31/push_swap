/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfernand <jfernand@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 14:57:29 by jfernand          #+#    #+#             */
/*   Updated: 2025/06/03 20:01:57 by jfernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	push_to_b_helper(t_node **a, int current_max, t_op_list *op_list)
{
	int	pos;

	pos = find_next_in_chunk_pos(a, current_max);
	if (pos != -1)
		bring_to_top(a, pos, stack_size((*a)), op_list);
}

void	push_to_b(t_node **a, t_node **b, int chunk_size, t_op_list *op_list)
{
	int	pushed;
	int	current_max;
	int	size;

	size = stack_size((*a));
	pushed = 0;
	current_max = chunk_size;
	while (pushed < size)
	{
		if ((*a)->index <= current_max)
		{
			pb(a, b, op_list);
			if (stack_size(*b) > 1 && (*b)->next
				&& (*b)->index < current_max - (chunk_size / 2)
				&& (*b)->index < (*b)->next->index)
				rb(b, op_list);
			pushed++;
		}
		else
			push_to_b_helper(a, current_max, op_list);
		if (pushed >= current_max)
			current_max += chunk_size;
	}
}

void	sort_and_push_to_a(t_node **a, t_node **b, t_op_list *op_list)
{
	int	max_pos;
	int	size;

	while (stack_size((*b)) != 0)
	{
		size = stack_size((*b));
		max_pos = find_max_pos(b);
		if (max_pos <= size / 2)
		{
			while (max_pos-- > 0)
				rb(b, op_list);
		}
		else
		{
			max_pos = size - max_pos;
			while (max_pos-- > 0)
				rrb(b, op_list);
		}
		pa(b, a, op_list);
	}
}

void	sort_big(t_node **a, t_node **b, int size, t_op_list *op_list)
{
	int			chunk_size;
	float		k;

	k = 2.15;
	chunk_size = square_root(size) * k;
	push_to_b(a, b, chunk_size, op_list);
	sort_and_push_to_a(a, b, op_list);
}
