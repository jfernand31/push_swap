/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate2_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfernand <jfernand@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 18:09:19 by jfernand          #+#    #+#             */
/*   Updated: 2025/05/29 18:25:59 by jfernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap_bonus.h"

static void	reverse_rotate(t_node **stack)
{
	t_node	*temp;
	t_node	*last;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	temp = *stack;
	while (temp->next->next != NULL)
		temp = temp->next;
	last = temp->next;
	temp->next = NULL;
	last->next = *stack;
}

void	rra2(t_node **stack_a)
{
	reverse_rotate(stack_a);
}

void	rrb2(t_node **stack_b)
{
	reverse_rotate(stack_b);
}

void	rrr2(t_node **stack_a, t_node **stack_b)
{
	reverse_rotate(stack_a);
	reverse_rotate(stack_b);
	
}
