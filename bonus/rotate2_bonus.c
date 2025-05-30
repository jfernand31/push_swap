/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate2_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfernand <jfernand@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 18:13:07 by jfernand          #+#    #+#             */
/*   Updated: 2025/05/29 18:25:49 by jfernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap_bonus.h"

static void	rotate(t_node **stack)
{
	t_node	*top;
	t_node	*temp;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	top = *stack;
	temp = top;
	temp = temp->next;
	*stack = temp;
	while (temp->next != NULL)
	{
		temp = temp->next;
	}
	temp->next = top;
	top->next = NULL;
}

void	ra2(t_node **stack_a)
{
	rotate(stack_a);
}

void	rb2(t_node **stack_b)
{
	rotate(stack_b);
}

void	rr2(t_node **stack_a, t_node **stack_b)
{
	rotate(stack_a);
	rotate(stack_b);
}
