/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfernand <jfernand@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 18:57:45 by jfernand          #+#    #+#             */
/*   Updated: 2025/05/27 17:52:51 by jfernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"

static int	calculate_chunk_size(int total)
{
	int size = total / 10;
	if (size < 1)
		size = 1;
	return size;
}

static int	push_chunk_to_b(t_node **a, t_node **b, int min, int max, int limit)
{
	int pushed;

	pushed = 0;
	while (pushed < limit && lst_size(a) > 0)
	{
		if ((*a)->index >= min && (*a)->index <= max)
		{
			pb (a, b);
			pushed ++;
		}
		else
			ra(a);
	}
	return (pushed);
}

static void	push_back_to_a(t_node **a, t_node **b)
{
	int index;

	while (lst_size(b) > 0)
	{
		index = get_biggest(b);
		bring_to_top(b, index, lst_size(b));
		pa(b, a);
	}
}

void	sort_big(t_node **stack_a, t_node **stack_b, int argc)
{
	int	total;
	int	chunck_size;
	int	min;
	int	max;

	total = argc - 1;
	chunck_size = calculate_chunk_size(total);
	min = 0;
	max = chunck_size - 1;
	if (is_sorted(stack_a))
		return ;
	while (min < total)
	{
		push_chunk_to_b(stack_a, stack_b, min, max, chunck_size);
		push_back_to_a(stack_a, stack_b);
		min += chunck_size;
		max += chunck_size;
		if (max >= total)
			max = total - 1;
		if (is_sorted(stack_a))
			break ;	
	}
}
