/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func_rotate.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfernand <jfernand@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/01 18:02:10 by jfernand          #+#    #+#             */
/*   Updated: 2025/06/03 17:08:11 by jfernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	rotate(t_node **st)
{
	t_node	*temp;
	t_node	*first;

	if(!st || !(*st)->next)
		return ;
	first = *st;
	*st = first->next;
	temp = *st;
	while (temp->next)
		temp = temp->next;
	temp->next = first;
	first->next = NULL;
}

void	ra(t_node **a, t_op_list *op_list)
{
	rotate(a);
	op_list_add(op_list, "ra");
}

void	rb(t_node **b, t_op_list *op_list)
{
	rotate(b);
	op_list_add(op_list, "rb");
}

void	rr(t_node **a, t_node **b, t_op_list *op_list)
{
	rotate(a);
	rotate(b);
	op_list_add(op_list, "rr");
}