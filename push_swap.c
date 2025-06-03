/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfernand <jfernand@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 20:01:25 by jfernand          #+#    #+#             */
/*   Updated: 2025/05/26 20:01:25 by jfernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"

void	push_swap(int size, t_node **stack_a, t_node **stack_b)
{
	int	*array;

	if (size == 2)
		sa(stack_a);
	else if (size == 3)
		sort_three(stack_a);
	else if (size == 4)
		sort_four(stack_a, stack_b);
	else if (size == 5)
		sort_five(stack_a, stack_b);
	else 
	{
		array = get_array(stack_a, size);
		sort_array(array, size);
		assign_index(array, stack_a, size);
		sort_big(stack_a, stack_b, size);
		free(array);
	}
}

int	main(int argc, char **argv)
{
	t_node	*stack_a;
	t_node	*stack_b;

	stack_b = NULL;
	if (argc < 2)
		return (0);
	else
		stack_a = parsing(argc, argv);
	if(!stack_a)
		return(1);
	if (is_sorted(stack_a))
		return (0);
	push_swap(argc - 1, &stack_a, &stack_b);
	ft_lstclear(&stack_a);
	ft_lstclear(&stack_b);
	return (0);
}
