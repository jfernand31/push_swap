/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_op_list.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfernand <jfernand@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 16:40:29 by jfernand          #+#    #+#             */
/*   Updated: 2025/06/03 20:12:09 by jfernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	op_list_add(t_op_list *list, char *op_name)
{
	t_op	*new;

	new = malloc(sizeof(t_op));
	if (!new)
		return ;
	new->name = ft_strdup(op_name);
	new->next = NULL;
	new->prev = list->tail;
	if (list->tail)
		list->tail->next = new;
	else
		list->head = new;
	list->tail = new;
	list->size++;
}

void	op_list_free(t_op_list *list)
{
	t_op	*current;
	t_op	*next;

	current = list->head;
	while (current)
	{
		next = current->next;
		free(current->name);
		free(current);
		current = next;
	}
	list->head = NULL;
	list->tail = NULL;
	list->size = 0;
}

void	op_list_init(t_op_list *list)
{
	list->head = NULL;
	list->tail = NULL;
	list->size = 0;
}

t_op	*new_op(char *name)
{
	t_op	*op;

	op = malloc(sizeof(t_op));
	if (!op)
		return (NULL);
	op->name = ft_strdup(name);
	op->next = NULL;
	op->prev = NULL;
	return (op);
}

void	replace_two_with_one(t_op_list *list, t_op *a, t_op *b, t_op *new)
{
	new->prev = a->prev;
	new->next = b->next;
	if (a->prev)
		a->prev->next = new;
	else
		list->head = new;
	if (b->next)
		b->next->prev = new;
	else
		list->tail = new;
	free(a->name);
	free(b->name);
	free(a);
	free(b);
	list->size--;
}
