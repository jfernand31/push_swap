/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfernand <jfernand@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 19:21:47 by jfernand          #+#    #+#             */
/*   Updated: 2025/05/30 19:21:47 by jfernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"

static int get_chunk_size(int total)
{
    if (total <= 100)
        return (total / 5);
    return (total / 10);
}

static void push_chunks_to_b(t_node **a, t_node **b, int total)
{
    int chunk = get_chunk_size(total);
    int min = 0;
    int max = chunk - 1;

    while (min < total)
    {
        int count = 0;

        // Push all elements from current chunk
        while (count < chunk && lst_size(a) > 0)
        {
            int idx = (*a)->index;
            if (idx >= min && idx <= max)
            {
                pb(a, b);
                count++;
                if (idx < min + (chunk / 2))
                    rb(b);
            }
            else
                ra(a);
        }

        min += chunk;
        max += chunk;
        if (max >= total)
            max = total - 1;
    }
}



static void push_back_to_a(t_node **a, t_node **b)
{
    while (lst_size(b) > 0)
    {
        int max_index = get_biggest(*b);
        bring_to_top(b, max_index, lst_size(b));
        pa(b, a);
    }
}

void sort_big(t_node **a, t_node **b, int argc)
{
    int total = argc - 1;

    if (is_sorted(*a))
        return;
    push_chunks_to_b(a, b, total);
    push_back_to_a(a, b);
}
