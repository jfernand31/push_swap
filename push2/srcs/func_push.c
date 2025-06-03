/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func_push.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfernand <jfernand@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/01 17:51:57 by jfernand          #+#    #+#             */
/*   Updated: 2025/06/01 17:51:57 by jfernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	push(t_node **st1, t_node **st2)
{
	t_node	*temp;

	if (!st1 || !*st1)
		return ;
	temp = *st1;
	*st1 = (*st1)->next;
	temp->next = *st2;
	*st2 = temp;
}

void	pa(t_node **b, t_node **a)
{
	push(b, a);
	ft_printf("pa\n");
}

void	pb(t_node **a, t_node **b)
{
	push(a, b);
	ft_printf("pb\n");
}
