/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_sort_big.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfernand <jfernand@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 19:29:29 by jfernand          #+#    #+#             */
/*   Updated: 2025/06/03 19:44:19 by jfernand         ###   ########.fr       */
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

void	bring_to_top(t_node **stack, int index, int size, t_op_list *op_list)
{
	if (index <= size / 2)
	{
		while (index-- > 0)
			ra(stack, op_list);
	}
	else
	{
		index = size - index;
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
