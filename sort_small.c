/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfernand <jfernand@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 16:59:52 by jfernand          #+#    #+#             */
/*   Updated: 2025/05/26 16:59:52 by jfernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"

void	sort_three(t_node **stack)
{
	t_node	*temp;
	int		third;
	int		case_num;

	temp = *stack;
	third = temp->next->next->value;
	case_num = get_case(temp->value, temp->next->value, third);
	if (case_num == 0)
		return ;
	if (case_num == 1)
	{
		sa(stack);
		ra(stack);
	}
	else if (case_num == 2)
		sa(stack);
	else if (case_num == 3)
		rra(stack);
	else if (case_num == 4)
		ra(stack);
	else if (case_num == 5)
	{
		sa(stack);
		rra(stack);
	}
}

void	sort_four(t_node **stack_a, t_node **stack_b)
{
	int	index;

	index = get_smallest(stack_a);
	if (index == 0)
		pb(stack_a, stack_b);
	else if (index == 1)
	{
		rra(stack_a);
		pb(stack_a, stack_b);
	}
	else if (index == 2)
	{
		ra(stack_a);
		ra(stack_a);
		pb(stack_a, stack_b);
	} 
	else if (index == 3)
	{
		ra(stack_a);
		pb(stack_a, stack_b);
	}
	sort_three(stack_a);
	pa(stack_b, stack_a);
}

static void	bring_to_top(t_node **stack, int index)
{
	if (index <= 2)
	{
		while (index-- > 0)
			ra(stack);
	}
	else
	{
		index = 5 - index;
		while (index-- > 0)
			rra(stack);
	}
}
void	sort_five(t_node **stack_a, t_node **stack_b)
{
	int	index;

	index = get_smallest(stack_a);
	bring_to_top(stack_a, index);
	pb (stack_a, stack_b);
	sort_four(stack_a, stack_b);
	pa(stack_b, stack_a);
}