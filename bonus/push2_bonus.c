/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push2_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfernand <jfernand@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 18:07:54 by jfernand          #+#    #+#             */
/*   Updated: 2025/05/29 18:26:06 by jfernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap_bonus.h"

static void	push(t_node **stack1, t_node **stack2)
{
	t_node	*pushed;

	if (!stack1 || !*stack1)
		return ;
	pushed = *stack1;
	*stack1 = pushed->next;
	pushed->next = *stack2;
	*stack2 = pushed;
}

void	pa2(t_node **stack_b, t_node **stack_a)
{
	push(stack_b, stack_a);
}

void	pb2(t_node **stack_a, t_node **stack_b)
{
	push(stack_a, stack_b);
}