/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfernand <jfernand@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 16:25:22 by jfernand          #+#    #+#             */
/*   Updated: 2025/05/27 17:48:46 by jfernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"

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

void	ra(t_node **stack_a)
{
	rotate(stack_a);
	ft_printf("%s\n", "ra");
}

void	rb(t_node **stack_b)
{
	rotate(stack_b);
	ft_printf("%s\n", "rb");
}

void	rr(t_node **stack_a, t_node **stack_b)
{
	rotate(stack_a);
	rotate(stack_b);
	ft_printf("%s\n", "rr");
}
