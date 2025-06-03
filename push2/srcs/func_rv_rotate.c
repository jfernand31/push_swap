/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func_rv_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfernand <jfernand@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/01 18:10:56 by jfernand          #+#    #+#             */
/*   Updated: 2025/06/03 17:09:02 by jfernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	rv_rotate(t_node **st)
{
	t_node	*temp;
	t_node	*last;
	t_node	*second_last;

	if (!st || !(*st)->next)
		return ;
	temp = *st;
	while (temp->next->next)
		temp = temp->next;
	second_last = temp;
	last = temp->next;
	second_last->next = NULL;
	last->next = *st;
	*st = last;
}

void	rra(t_node **a, t_op_list *op_list)
{
	rv_rotate(a);
	op_list_add(op_list, "rra");
}

void	rrb(t_node **b, t_op_list *op_list)
{
	rv_rotate(b);
	op_list_add(op_list, "rrb");
}

void	rrr(t_node **a, t_node **b, t_op_list *op_list)
{
	rv_rotate(a);
	rv_rotate(b);
	op_list_add(op_list, "rrr");
}
