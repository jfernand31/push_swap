/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfernand <jfernand@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 18:57:45 by jfernand          #+#    #+#             */
/*   Updated: 2025/05/26 18:57:45 by jfernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"

void	sort_big(t_node **stack_a, t_node **stack_b, int argc)
{
	int	max_index;
	int max_bits;
	int	i;
	int	count;
	t_node	*temp;

	max_index = argc - 2;
	max_bits = 0;
	while ((max_index >> max_bits) != 0)
		max_bits++;
	i = 0;
	while (i < (max_bits))
	{
		count = ft_lstsize(stack_a);
		while (count--)
		{
			if (((*stack_a)->index & (1 << i)) == 0)
				pb(stack_a, stack_b);
			else
				ra(stack_a);
		}
		while (ft_lstsize(stack_b) > 0)
			pa(stack_b, stack_a);
		i++;
	}
}
