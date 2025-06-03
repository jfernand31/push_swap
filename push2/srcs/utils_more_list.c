/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_more_list.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfernand <jfernand@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 17:53:34 by jfernand          #+#    #+#             */
/*   Updated: 2025/06/03 18:04:22 by jfernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void print_ops(t_op_list *list)
{
    t_op *cur;

    cur = list->head;
    while (cur)
    {
        ft_putendl_fd(cur->name, 1);
        cur = cur->next;
    }
}
