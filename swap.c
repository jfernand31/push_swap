/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfernand <jfernand@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 15:55:00 by jfernand          #+#    #+#             */
/*   Updated: 2025/05/27 17:34:28 by jfernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"

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

void	sa(t_node **stack_a)
{
	swap_top_two(stack_a);
	ft_printf("%s\n", "sa");
}
void	sb(t_node **stack_b)
{
	swap_top_two(stack_b);
	ft_printf("%s\n", "sb");
}
void	ss(t_node **stack_a, t_node **stack_b)
{
	swap_top_two(stack_a);
	swap_top_two(stack_b);
	ft_printf("%s\n", "ss");
}
