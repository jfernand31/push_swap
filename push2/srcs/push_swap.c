/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfernand <jfernand@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/31 09:37:08 by jfernand          #+#    #+#             */
/*   Updated: 2025/06/03 19:56:57 by jfernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	*get_array(t_node **stack, int size)
{
	int		*array;
	t_node	*temp;
	int		i;

	i = 0;
	array = malloc(sizeof(int) * size);
	if (!array)
		return (NULL);
	temp = *stack;
	while (temp)
	{
		array[i] = temp->value;
		temp = temp->next;
		i++;
	}
	return (array);
}

void	sort_array(int *numbers, int size)
{
	int	i;
	int	sorted;
	int	temp;

	i = 0;
	sorted = 0;
	while (!sorted)
	{
		sorted = 1;
		i = 0;
		while (i < (size - 1))
		{
			if (numbers[i] > numbers[i + 1])
			{
				temp = numbers[i];
				numbers[i] = numbers[i + 1];
				numbers[i + 1] = temp;
				sorted = 0;
			}
			i++;
		}
	}
}

static void	assign_index(t_node **a, int *numbers, int size)
{
	int		i;
	t_node	*temp;

	temp = *a;
	while (temp)
	{
		i = 0;
		while (i < size)
		{
			if (temp->value == numbers[i])
			{
				temp->index = i;
				break ;
			}
			i++;
		}
		temp = temp->next;
	}
}

void	push_swap(t_node **a, t_node **b, int size, t_op_list *op_list)
{
	int	*array;

	if (is_sorted(*a))
		return ;
	if (size == 2)
		sa(a, op_list);
	else if (size == 3)
		sort_three(a, op_list);
	else if (size > 3 && size < 6)
		sort_five(a, b, size, op_list);
	else if (size > 5)
	{
		array = get_array(a, size);
		if (!array)
			return ;
		sort_array(array, size);
		assign_index(a, array, size);
		sort_big(a, b, size, op_list);
		free(array);
	}
}
