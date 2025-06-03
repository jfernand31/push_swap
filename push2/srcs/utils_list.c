/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfernand <jfernand@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/31 08:32:40 by jfernand          #+#    #+#             */
/*   Updated: 2025/06/03 19:58:36 by jfernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	add_to_back(t_node **lst, t_node *new)
{
	t_node	*temp;

	if (!lst || !new)
		return ;
	if (*lst == NULL)
	{
		*lst = new;
		return ;
	}
	temp = *lst;
	while (temp->next != NULL)
	{
		temp = temp->next;
	}
	temp->next = new;
}

t_node	*new_node(int value)
{
	t_node	*node;

	node = malloc(sizeof(*node));
	if (node == NULL)
		return (NULL);
	node->value = value;
	node->next = NULL;
	return (node);
}

int	stack_size(t_node *lst)
{
	int	size;

	size = 0;
	while (lst)
	{
		size++;
		lst = lst->next;
	}
	return (size);
}

void	stack_clear(t_node **lst)
{
	t_node	*temp;
	t_node	*next;

	if (!lst || !*lst)
		return ;
	temp = *lst;
	while (temp != NULL)
	{
		next = temp->next;
		free(temp);
		temp = next;
	}
	*lst = NULL;
}

void	remove_two_nodes(t_op_list *list, t_op *a, t_op *b)
{
	if (a->prev)
		a->prev->next = b->next;
	else
		list->head = b->next;
	if (b->next)
		b->next->prev = a->prev;
	else
		list->tail = a->prev;
	free(a->name);
	free(b->name);
	free(a);
	free(b);
	list->size -= 2;
}
