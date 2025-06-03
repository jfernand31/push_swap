/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap2_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfernand <jfernand@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 18:10:51 by jfernand          #+#    #+#             */
/*   Updated: 2025/05/29 18:25:37 by jfernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap_bonus.h"

static void	swap_top_two(t_node **stack)
{
	t_node	*first;
	t_node *second;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	first = *stack;
	second = first->next;
	first->next = second->next;
	second->next =	first;
	*stack = second;
}

void	sa2(t_node **stack_a)
{
	swap_top_two(stack_a);
}
void	sb2(t_node **stack_b)
{
	swap_top_two(stack_b);
}
void	ss2(t_node **stack_a, t_node **stack_b)
{
	swap_top_two(stack_a);
	swap_top_two(stack_b);
}
