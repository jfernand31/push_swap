/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfernand <jfernand@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/01 18:20:36 by jfernand          #+#    #+#             */
/*   Updated: 2025/06/03 20:08:26 by jfernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	swap(t_node **st)
{
	t_node	*first;
	t_node	*second;

	if (!st || !*st || !(*st)->next)
		return ;
	first = *st;
	second = first->next;
	first->next = second->next;
	second->next = first;
	*st = second;
}

void	sa(t_node **a, t_op_list *op_list)
{
	swap(a);
	op_list_add(op_list, "sa");
}

void	sb(t_node **b, t_op_list *op_list)
{
	swap(b);
	op_list_add(op_list, "sb");
}

void	ss(t_node **a, t_node **b, t_op_list *op_list)
{
	swap(a);
	swap(b);
	op_list_add(op_list, "ss");
}
