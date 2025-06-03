/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfernand <jfernand@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/01 18:30:29 by jfernand          #+#    #+#             */
/*   Updated: 2025/06/03 19:43:35 by jfernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	sort_three(t_node **a, t_op_list *op_list)
{
	int	a_val;
	int	b_val;
	int	c_val;

	if (!a || !*a || !(*a)->next || !(*a)->next->next)
		return ;
	a_val = (*a)->value;
	b_val = (*a)->next->value;
	c_val = (*a)->next->next->value;
	if (a_val > b_val && b_val < c_val && a_val < c_val)
		sa(a, op_list);
	else if (a_val > b_val && b_val > c_val)
	{
		sa(a, op_list);
		rra(a, op_list);
	}
	else if (a_val > b_val && b_val < c_val && a_val > c_val)
		ra(a, op_list);
	else if (a_val < b_val && b_val > c_val && a_val < c_val)
	{
		sa(a, op_list);
		ra(a, op_list);
	}
	else if (a_val < b_val && b_val > c_val && a_val > c_val)
		rra(a, op_list);
}
