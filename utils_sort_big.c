/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfernand <jfernand@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 18:27:11 by jfernand          #+#    #+#             */
/*   Updated: 2025/05/26 18:27:11 by jfernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"

int	*get_array(t_node **stack, int argc)
{
	int		*array;
	t_node	*temp;
	int		i;

	i = 0;
	array = malloc(sizeof(int) * (argc - 1));
	if (!array)
		return (NULL);
	temp = *stack;
	while (temp != NULL)
	{
		array[i] = temp->value;
		temp = temp->next;
		i++;
	}
	return (array);
}

void	sort_array(int *numbers, int argc)
{
	int	i;
	int	temp;
	int	sorted;

	sorted = 0;
	while (!sorted)
	{
		sorted = 1;
		i = 0;
		while (i < (argc - 2))
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

void	assign_index(int *numbers, t_node **stack, int argc)
{
	t_node	*temp;
	int		i;

	i = 0;
	while (i < (argc - 1))
	{
		temp = *stack;
		while (temp != NULL)
		{
			if (numbers[i] == temp->value)
			{
				temp->index = i;
				break ;
			}
			temp = temp->next;
		}
		i++;
	}
}
