/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfernand <jfernand@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 14:57:29 by jfernand          #+#    #+#             */
/*   Updated: 2025/06/03 18:00:04 by jfernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	square_root(int size)
{
	int	i;

	i = 0;
	while ((i * i) < size)
	{
		i++;
	}
	return (i);
}

int	index_pos(t_node **st, int target)
{
	t_node	*temp;
	int		i;

	i = 0;
	temp = *st;
	while (temp)
	{
		if (temp->index == target)
		{
			return (i);
		}
		temp = temp->next;
		i++;
	}
	return (-1);
}

int	find_max_pos(t_node **st)
{
	t_node	*temp;
	int		current_max;
	int		i;
	int		max_pos;

	max_pos = 0;
	temp = *st;
	current_max = temp->index;
	i = 0;
	while (temp)
	{
		if (temp->index > current_max)
		{
			current_max = temp->index;
			max_pos = i;
		}
		temp = temp->next;
		i++;
	}	
	return (max_pos);
}

void	bring_to_top(t_node **stack, int index, int total_size, t_op_list *op_list)
{
	if (index <= total_size / 2)
	{
		while (index-- > 0)
			ra(stack, op_list);
	}
	else
	{
		index = total_size - index;
		while (index-- > 0)
			rra(stack, op_list);
	}
}

int	find_next_in_chunk_pos(t_node **stack, int current_max)
{
	t_node	*temp;
	int		pos;

	pos = 0;
	temp = *stack;
	while (temp)
	{
		if (temp->index <= current_max)
			return (pos);
		temp = temp->next;
		pos++;
	}
	return (-1);
}

void	push_to_b(t_node **a, t_node **b, int chunk_size, t_op_list *op_list)
{
	int pushed;
	int current_max;
	int	pos;
	int	size;

	size = stack_size((*a));
	pushed = 0;
	current_max = chunk_size;
	while (pushed < size)
	{
		if ((*a)->index <= current_max)
		{
			pb(a, b, op_list);
			if ((*b)->index < current_max - (chunk_size / 2))
				rb(b, op_list);
			pushed++;
		}
		else 
		{
			pos = find_next_in_chunk_pos(a, current_max);
			if (pos != -1)
				bring_to_top(a, pos, stack_size((*a)), op_list);
		}
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
