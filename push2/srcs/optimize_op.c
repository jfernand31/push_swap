/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   optimize_op.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfernand <jfernand@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 17:27:09 by jfernand          #+#    #+#             */
/*   Updated: 2025/06/03 17:52:54 by jfernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int is_combinable(char *op1, char *op2)
{
    if ((!ft_strcmp(op1, "ra") && !ft_strcmp(op2, "rb")) ||
        (!ft_strcmp(op1, "rb") && !ft_strcmp(op2, "ra")))
        return 1;
    if ((!ft_strcmp(op1, "rra") && !ft_strcmp(op2, "rrb")) ||
        (!ft_strcmp(op1, "rrb") && !ft_strcmp(op2, "rra")))
        return 1;
    if ((!ft_strcmp(op1, "sa") && !ft_strcmp(op2, "sb")) ||
        (!ft_strcmp(op1, "sb") && !ft_strcmp(op2, "sa")))
        return 1;
    return 0;
}

char *get_combined_name(char *op1, char *op2)
{
    if ((ft_strcmp(op1, "ra") == 0 && ft_strcmp(op2, "rb") == 0) ||
        (ft_strcmp(op1, "rb") == 0 && ft_strcmp(op2, "ra") == 0))
        return ("rr");
    if ((ft_strcmp(op1, "rra") == 0 && ft_strcmp(op2, "rrb") == 0) ||
        (ft_strcmp(op1, "rrb") == 0 && ft_strcmp(op2, "rra") == 0))
        return ("rrr");
    if ((ft_strcmp(op1, "sa") == 0 && ft_strcmp(op2, "sb") == 0) ||
        (ft_strcmp(op1, "sb") == 0 && ft_strcmp(op2, "sa") == 0))
        return ("ss");
    return (NULL);
}

int are_opposites(char *op1, char *op2)
{
    if ((ft_strcmp(op1, "pa") == 0 && ft_strcmp(op2, "pb") == 0) ||
        (ft_strcmp(op1, "pb") == 0 && ft_strcmp(op2, "pa") == 0))
        return 1;
    if ((ft_strcmp(op1, "ra") == 0 && ft_strcmp(op2, "rra") == 0) ||
        (ft_strcmp(op1, "rra") == 0 && ft_strcmp(op2, "ra") == 0))
        return 1;
    if ((ft_strcmp(op1, "rb") == 0 && ft_strcmp(op2, "rrb") == 0) ||
        (ft_strcmp(op1, "rrb") == 0 && ft_strcmp(op2, "rb") == 0))
        return 1;
    return 0;
}

void	set_back_to_prev_or_head(t_op **cur, t_op *node, t_op_list *list)
{
	if (node)
		*cur = node;
	else
		*cur = list->head;
}

void	optimize_op(t_op_list *list)
{
	t_op	*cur;
	t_op	*combined;
	t_op	*prev;

	cur = list->head;
	while (cur && cur->next)
	{
		if (is_combinable(cur->name, cur->next->name))
		{
			combined = new_op(get_combined_name(cur->name, cur->next->name));
			replace_two_with_one(list, cur, cur->next, combined);
			set_back_to_prev_or_head(&cur, combined->prev, list);
		}
		else if (are_opposites(cur->name, cur->next->name))
		{
			prev = cur->prev;
			remove_two_nodes(list, cur, cur->next);
			set_back_to_prev_or_head(&cur, prev, list);
		}
		else
			cur = cur->next;
	}
}


