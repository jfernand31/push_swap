/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfernand <jfernand@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 18:45:00 by jfernand          #+#    #+#             */
/*   Updated: 2025/05/28 18:45:00 by jfernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"

static int	get_case(int first, int second , int third)
{
	if (first < second && second < third)
		return (0);
	else if (first < second && second > third && first < third)
		return (1);
	else if (first > second && second < third && first < third)
		return (2);
	else if (first < second && second > third && first > third)
		return (3);
	else if (first > second && second < third && first > third)
		return (4);
	else if (first > second && second > third)
		return (5);
    else
        return (-1);
}

static void	sort_case(t_node **stack, int case_num)
{
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

void	sort_three(t_node **stack)
{
	int		case_num;
	int		first;
	int		second;
	int		third;

	if (!stack || !*stack || !(*stack)->next || !(*stack)->next->next)
		return ;
	if (is_sorted(*stack))
		return ;
	first = (*stack)->value;
	second = (*stack)->next->value;
	third = (*stack)->next->next->value;
	case_num = get_case(first, second, third);
	sort_case(stack, case_num);
}
