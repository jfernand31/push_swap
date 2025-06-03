/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_five_or_less.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfernand <jfernand@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/01 18:37:57 by jfernand          #+#    #+#             */
/*   Updated: 2025/06/01 18:37:57 by jfernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static int find_smallest_pos(t_node *stack)
{
    int pos;
    int i;
    int smallest;
    t_node *temp;

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

static void	push_smallest_to_b(t_node **a, t_node **b, int count, int size)
{
    int pos;

    while (count > 0)
    {
        pos = find_smallest_pos(*a);
        if (pos == 0)
        {
            pb(a, b);
            count--;
			size--;
        }
        else if (pos <= size / 2)
            ra(a);
        else
            rra(a);
    }
}

void	sort_five(t_node **a, t_node **b, int size)
{
    int push_count;

	push_count = size - 3;
    push_smallest_to_b(a, b, push_count, size);
    sort_three(a);
    while (stack_size(*b) > 0)
        pa(b, a);
}
