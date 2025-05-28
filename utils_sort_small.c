/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_sort_small.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfernand <jfernand@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 17:52:35 by jfernand          #+#    #+#             */
/*   Updated: 2025/05/27 18:01:25 by jfernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"

int	is_sorted(t_node **stack)
{
	t_node	*temp;

	if (!stack || !*stack)
		return (1);

	temp = *stack;
	while (temp->next != NULL)
	{
		if (temp->value > temp->next->value)
			return (0);
		temp = temp->next;
	}
	return (1);
}

int	get_smallest(t_node **stack)
{
	t_node	*temp;
	int		number;
	int		min_index;
	int		current_index;

	if (!stack || !*stack)
		return (-1);
	temp = *stack;
	number = temp->value;
	min_index = 0;
	current_index = 0;
	while (temp != NULL)
	{
		if (temp->value < number)
		{
			number = temp->value;
			min_index = current_index;
		}
		temp = temp->next;
		current_index++;
	}
	return (min_index);
}

void	bring_to_top(t_node **stack, int index, int total_size)
{
	if (index <= total_size / 2)
	{
		while (index-- > 0)
			ra(stack);
	}
	else
	{
		index = total_size - index;
		while (index-- > 0)
			rra(stack);
	}
}
