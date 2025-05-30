/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_four.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfernand <jfernand@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 18:44:57 by jfernand          #+#    #+#             */
/*   Updated: 2025/05/28 18:44:57 by jfernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"

void	sort_four(t_node **stack_a, t_node **stack_b)
{
	int	index;

	if (is_sorted(*stack_a))
		return ;
	index = get_smallest(*stack_a);
	bring_to_top(stack_a, index, lst_size(stack_a));
	pb(stack_a, stack_b);
	sort_three(stack_a);
	pa(stack_b, stack_a);
}
