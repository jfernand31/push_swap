/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func_rv_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfernand <jfernand@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/01 18:10:56 by jfernand          #+#    #+#             */
/*   Updated: 2025/06/01 18:10:56 by jfernand         ###   ########.fr       */
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

void	rra(t_node **a)
{
	rv_rotate(a);
	ft_printf("rra\n");
}

void	rrb(t_node **b)
{
	rv_rotate(b);
	ft_printf("rrb\n");
}

void	rrr(t_node **a, t_node **b)
{
	rv_rotate(a);
	rv_rotate(b);
	ft_printf("rrr\n");
}
