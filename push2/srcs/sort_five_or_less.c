/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_five_or_less.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfernand <jfernand@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/01 18:37:57 by jfernand          #+#    #+#             */
/*   Updated: 2025/06/03 20:16:21 by jfernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static int	find_smallest_pos(t_node *stack)
{
	int		pos;
	int		i;
	int		smallest;
	t_node	*temp;

	pos = 0;
	i = 0;
	smallest = stack->value;
	temp = stack;
	while (temp)
	{
		if (temp->value < smallest)
		{
			smallest = temp->value;
			pos = i;
		}
		temp = temp->next;
		i++;
	}
	return (pos);
}

static void	smlst_to_b(t_node **a, t_node **b, int count, t_op_list *op_list)
{
	int	pos;
	int	size;

	size = stack_size((*a));
	while (count > 0)
	{
		pos = find_smallest_pos(*a);
		if (pos == 0)
		{
			pb(a, b, op_list);
			count--;
			size--;
		}
		else if (pos <= size / 2)
			ra(a, op_list);
		else
			rra(a, op_list);
	}
}

void	sort_the_rest(t_node **a, t_op_list *op_list)
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

void	sort_five(t_node **a, t_node **b, int size, t_op_list *op_list)
{
	int	push_count;

	push_count = size - 3;
	smlst_to_b(a, b, push_count, op_list);
	sort_the_rest(a, op_list);
	while (stack_size(*b) > 0)
		pa(b, a, op_list);
}
