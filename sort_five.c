/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfernand <jfernand@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 16:59:52 by jfernand          #+#    #+#             */
/*   Updated: 2025/05/26 16:59:52 by jfernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"

void	sort_five(t_node **stack_a, t_node **stack_b)
{
	int	index;

	if (is_sorted(stack_a))
		return ;
	index = get_smallest(stack_a);
	bring_to_top(stack_a, index, lst_size(stack_a));
	pb (stack_a, stack_b);
	sort_four(stack_a, stack_b);
	pa(stack_b, stack_a);
}